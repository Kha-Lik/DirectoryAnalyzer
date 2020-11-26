#include "mainwindow.h"

#include <QFileDialog>
#include <QFileSystemModel>
#include <string>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Disk space analyzer");
    setGeometry(100, 100, 610, 600);
    setMinimumSize(600, 600);

    inputLabel = new QLabel(this);
    inputLabel->setGeometry(10, 10, 85, 25);
    inputLabel->setText("Selected directory: ");

    selectedPathField = new QLineEdit(this);
    selectedPathField->show();
    selectedPathField->setGeometry(105, 10, 200, 25);
    selectedPathField->setReadOnly(true);

    historyList = new QListWidget(this);
    historyList->setSelectionMode(QAbstractItemView::SingleSelection);
    historyList->setGeometry(10, 45, 395, 90);

    inputButton = new QPushButton(this);
    inputButton->setGeometry(315, 10, 90, 25);
    inputButton->setText("Select directory");

    showHistoryButton = new QPushButton(this);
    showHistoryButton->setGeometry(415, 45, 90, 90);
    showHistoryButton->setText("Show\nHistory");

    showSelectedDirButton = new QPushButton(this);
    showSelectedDirButton->setGeometry(515, 45, 90, 90);
    showSelectedDirButton->setText("Show\nSelected");

    directoryTree = new QTreeView(this);
    directoryTree->setGeometry(10, 145, 595, 545);
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
    FileHelper helper;
    writePathToFile(helper);
    showTree();
    showHistory();
}

void MainWindow::showTree(){
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(path);
    directoryTree->setModel(model);
    directoryTree->setRootIndex(model->index(path));
    directoryTree->setSortingEnabled(true);
}

void MainWindow::writePathToFile(FileHelper helper){
    helper.writeStringToFile(path.toStdString(), "history.txt");
}

void MainWindow::showHistory(){
    std::vector<std::string> history;
    FileHelper helper;
    history = helper.readAllLines("history.txt");
    historyList->clear();

    for (unsigned short i = 0; i < history.size(); i++){
        QListWidgetItem *newItem = new QListWidgetItem;
        short index = history.size() - i - 1;
        QString content = QString::fromStdString(history[index]);
        newItem->setText(content);
        historyList->insertItem(i, newItem);
    }
}

void MainWindow::showSelectedDir(){
    path = historyList->selectedItems().first()->text();
    showTree();
}

