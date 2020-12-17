#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QTreeView>
#include "FileHelper.h"
#include <DbHelper.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLineEdit *selectedPathField;
    QPushButton *inputButton;
    QPushButton *showSelectedDirButton;
    QPushButton *showHistoryWindowButton;
    QTreeView *directoryTree;

public slots:
    void openFileDialog();
    void showSelectedDir();
    void showHistoryWindow();

private:
    QString path;
    QLabel *inputLabel;
    QListWidget *historyList;
    DbHelper *dbHelper;

    void showTree();
    void showHistory();
    void writePathToFile(FileHelper helper);
};
#endif // MAINWINDOW_H
