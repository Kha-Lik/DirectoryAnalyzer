#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QTreeView>
#include "FileHelper.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //macros

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLineEdit *selectedPathField;
    QPushButton *inputButton;
    QPushButton *showHistoryButton;
    QPushButton *showSelectedDirButton;
    QTreeView *directoryTree;

public slots:
    void openFileDialog();
    void showHistory();
    void showSelectedDir();

private:
    QString path;
    QLabel *inputLabel;
    QListWidget *historyList;

    void showTree();
    void writePathToFile(FileHelper helper);
};
#endif // MAINWINDOW_H
