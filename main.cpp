#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QObject::connect(w.inputButton, &QPushButton::clicked, &w, &MainWindow::openFileDialog);
    QObject::connect(w.showSelectedDirButton, &QPushButton::clicked, &w, &MainWindow::showSelectedDir);
    QObject::connect(w.showHistoryWindowButton, &QPushButton::clicked, &w, &MainWindow::showHistoryWindow);

    w.show();
    return a.exec();

}
