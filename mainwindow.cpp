#include "mainwindow.h"

#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Disk space analyzer");
    setGeometry(100, 100, 600, 500);
    setMinimumSize(600, 500);

    inputLabel = new QLabel(this);
    inputLabel->setGeometry(10, 10, 85, 25);
    inputLabel->setText("Selected directory: ");

    selectedPathField = new QLineEdit(this);
    selectedPathField->setGeometry(105, 10, 200, 25);
    selectedPathField->setReadOnly(true);

    inputButton = new QPushButton(this);
    inputButton->setGeometry(315, 10, 90, 25);
    inputButton->setText("Select directory");

    directoryTree = new QTreeView(this);
    directoryTree->setGeometry(10, 45, 580, 445);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openFileDialog(){
    QFileDialog *fileDialog = new QFileDialog(this);
    path = fileDialog->getExistingDirectory(this, tr("Select initial directory"), "/",
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);
    selectedPathField->setText(path);
}

