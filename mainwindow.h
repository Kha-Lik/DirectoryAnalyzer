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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLineEdit *selectedPathField;
    QPushButton *inputButton;
    QPushButton *showSelectedDirButton;
    QTreeView *directoryTree;

public slots:
    void openFileDialog();
    void showSelectedDir();

private:
    QString path;
    QLabel *inputLabel;
    QListWidget *historyList;

    void showTree();
    void showHistory();
    void writePathToFile(FileHelper helper);
};
#endif // MAINWINDOW_H
