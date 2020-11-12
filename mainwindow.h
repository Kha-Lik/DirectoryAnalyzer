#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTreeView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLineEdit *selectedPathField;
    QPushButton *inputButton;
    QTreeView *directoryTree;

public slots:
    void openFileDialog();

private:
    QString path;
    QLabel *inputLabel;
};
#endif // MAINWINDOW_H
