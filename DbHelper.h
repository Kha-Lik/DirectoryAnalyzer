#ifndef DBHELPER_H
#define DBHELPER_H

#include <QtSql>
#include <vector>
#include <DirLogRow.h>

using namespace std;

class DbHelper{
    private:
        QSqlDatabase _database;
        int GetDirId(QString dir);
    public:
        DbHelper();
        ~DbHelper();
        void WriteLog(QString directory, QString size);
        vector<DirLogRow> ReadLog();
        vector<DirLogRow> ReadLog(QString directory);
        vector<DirLogRow> ReadLog(QDate date);

};

#endif // DBHELPER_H
