#include "HistoryWindow.h"
#include <QHeaderView>
#include <QSqlQuery>

HistoryWindow::HistoryWindow(DbHelper &helper)
{
    this->helper = helper;
    setWindowTitle("History");
    setGeometry(200, 200, 600, 700);
    createTable();
}


void HistoryWindow::createTable(){

    tableWidget = new QTableWidget(this);
    tableWidget->setGeometry(10, 10, 580, 680);

    tableWidget->setColumnCount(3);
       tableWidget->setShowGrid(true);
       tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
       tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
       tableWidget->setHorizontalHeaderLabels(QStringList() << ("Directory")
                                                            << ("Size")
                                                            << ("Date"));
       tableWidget->horizontalHeader()->setStretchLastSection(true);

       vector<DirLogRow> logs = helper.ReadLog();

       for(unsigned int i = 0; i < logs.size(); i++){
           tableWidget->insertRow(i);
           tableWidget->setItem(i,0, new QTableWidgetItem(logs[i].DirectoryName));
           tableWidget->setItem(i,1, new QTableWidgetItem(logs[i].Size));
           tableWidget->setItem(i,2, new QTableWidgetItem(logs[i].OpenDate));
       }
       tableWidget->resizeColumnsToContents();
}
