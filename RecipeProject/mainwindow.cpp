#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLineEdit>
#include <QTextBrowser>
#include "Recipe.h"
#include "error404.h"
#include <QMessageBox>

#define HARD 1
#define MEDIUM 2 //3 constants
#define EASY 3

Food temp("temp");
Recipe r;

error404 e("Recipe was not found or doesn't exist");

MainWindow::MainWindow(QWidget *parent) //initialises the main window of App
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ConorsCookhouse"); //Sets title to ConorsCookhouse
}

MainWindow::~MainWindow() //cleans up resources used by GUI when app is closed
{
    delete ui;
}

void MainWindow::on_actionExit_triggered() //exits the app
{
    exit(0);
}

void MainWindow::on_searchButton_clicked() // performs a search for recipe based on text entered in search box
{
    try {
        searchList(ui->lineEdit->text().toStdString(), Recipe::getRecipeList());
        ui->textBrowser->clear();
        ui->textBrowser->setText(QString::fromStdString(r.instructionsGlobal)); //shows instructions for recipe
        ui->textBrowser_2->clear();
        ui->textBrowser_2->setText(QString::fromStdString(r.getIngredients())); //shows ingredients for recipe
    } catch (const error404& error) {
        ui->lineEdit->clear();
        QMessageBox::information(this, tr("Error 404"), QString::fromStdString(error.what())); //displaus an error message using QMessageBox
    }
}

string MainWindow::searchList(const string &str, const vector<string> &vectorS) //if recipe is not found, error404 exception is thrown
{
    if (any_of(vectorS.begin(), vectorS.end(), [](string s) {return s == str;})) {
        r = Recipe::getRecipeByName(str);
        return str;
    }
    throw error404("Recipe was not found or doesn't exist");
}


void MainWindow::on_radioButton_4_clicked() // HARD - these 3 display lsit of recipies that match difficulty clicked
{
    ui->textBrowser->setText(QString::fromStdString(Recipe::getDifficultyFromList(HARD)));
}

void MainWindow::on_radioButton_3_clicked() // MEDIUM
{
    ui->textBrowser->setText(QString::fromStdString(Recipe::getDifficultyFromList(MEDIUM)));
}

void MainWindow::on_radioButton_2_clicked() // EASY
{
    ui->textBrowser->setText(QString::fromStdString(Recipe::getDifficultyFromList(EASY)));
}

void MainWindow::setup() //initializes test data for app, creates a Recipe and adds it to list of recipies
{
    vector<Ingredients> tempV;
    string basicString = "flour, dry yeast, warm water, onion, tomato, capsicum";
    Ingredients ingredients1(basicString);
    tempV.push_back(ingredients1);
    Food ingredients("tempV", tempV);
    Recipe r("Food", ingredients, "Hard", 4, basicString);
    r.addToList();
}
