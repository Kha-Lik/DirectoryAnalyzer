#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QObject::connect(w.inputButton, &QPushButton::clicked, &w, &MainWindow::openFileDialog);

    w.show();
    return a.exec();
}
