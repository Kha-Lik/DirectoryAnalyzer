#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QTableWidget>
#include <DbHelper.h>

class HistoryWindow : public QWidget {
    private:
        QLineEdit *dirPath;
        QCalendarWidget *calendar;
        QTableWidget *tableWidget;
        DbHelper helper;

        void createTable();

    public:
        QPushButton *readFullLogBtn;
        QPushButton *readDirLogBtn;

        HistoryWindow(DbHelper &helper);

    public slots:
        void readFullLog();
        void readDirLog();

};

#endif // HISTORYWINDOW_H
