#include <DbHelper.h>

DbHelper::DbHelper(){
    _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName("log.sqlite");
    _database.open();

    QString createTableDirs="CREATE TABLE IF NOT EXISTS DIRECTORIES("
                            "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                            "PATH VARCHAR(255)"
                            ");";
    if(!_query.exec(createTableDirs)) throw -2;

    QString createTableLogs = "PRAGMA foreign_keys=on;"
                              "CREATE TABLE IF NOT EXISTS LOGS("
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                              "DIR_ID INTEGER NOT NULL,"
                              "SIZE VARCHAR(15),"
                              "OPEN_DATE TEXT,"
                              "FOREIGN KEY (DIR_ID) REFERENCES DIRECTORIES(ID));";
    if(!_query.exec(createTableLogs)) throw -2;

}

void DbHelper::WriteLog(QString directory, QString size){
    QDate date = QDate::currentDate();
    int dirID = GetDirId(directory);

    QString insert = QString("INSERT INTO LOGS(DIR_ID, SIZE, OPEN_DATE) VALUES(%1, %2, %3);")
                                .arg(dirID).arg(size).arg(date.toString());

}

int DbHelper::GetDirId(QString dir){
    QString selectDirs = QString("SELECT ID FROM DIRECTORIES WHERE PATH LIKE %1;").arg(dir);
    if(!_query.exec(selectDirs)) throw -3;
    _query.next();
    int dirID = _query.value(0).toInt();
    if(dirID == 0){
        QString insert = QString("INSERT INTO DIRECTORIES(PATH) VALUES(%1);").arg(dir);
        _query.exec(insert);
        if(!_query.exec(selectDirs)) throw -3;
        _query.next();
        dirID = _query.value(0).toInt();
    }
    return dirID;
}

DbHelper::~DbHelper(){
    _database.close();
}
