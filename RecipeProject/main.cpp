#include "Recipe.h"
#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QString>
#include <QDebug>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QJsonObject>
#include <QByteArray>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
