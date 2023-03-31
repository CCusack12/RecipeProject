#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextBrowser>
#include <QMessageBox>
#include "Recipe.h"
#include "error404.h"

#define HARD 1
#define MEDIUM 2
#define EASY 3

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_searchButton_clicked();
    void on_radioButton_4_clicked(); // HARD   //defined as constants, each having an integer value
    void on_radioButton_3_clicked(); // MEDIUM
    void on_radioButton_2_clicked(); // EASY

private:
    Ui::MainWindow *ui; //private pointer
    Recipe r; //two private data members
    error404 e;

    static std::string searchList(const std::string& str, const std::vector<std::string>& vectorS); //public static member function, uses string and vector of strings
                                                                                                    //as input parameters and returns a string
public:
    static void setup(); //takes no input parameters and returns void
};

#endif // MAINWINDOW_H
