#include <DbHelper.h>

DbHelper::DbHelper(){
    _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName("log.sqlite");
    if (!_database.open()) throw -4;
    QSqlQuery query;

    QString createTableDirs="CREATE TABLE IF NOT EXISTS DIRECTORIES("
                            "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                            "PATH VARCHAR(255)"
                            ");";
    if(!query.exec(createTableDirs)) throw -2;

    QString createTableLogs = "CREATE TABLE IF NOT EXISTS LOGS("
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                              "DIR_ID INTEGER NOT NULL,"
                              "SIZE VARCHAR(15),"
                              "OPEN_DATE TEXT,"
                              "FOREIGN KEY (DIR_ID) REFERENCES DIRECTORIES(ID));";
    if(!query.exec(createTableLogs)) throw -2;

}

void DbHelper::WriteLog(QString directory, QString size){
    QString date = QDate::currentDate().toString(Qt::DateFormat::DefaultLocaleLongDate);
    int dirID = GetDirId(directory);
    QSqlQuery query;

    QString insert = QString("INSERT INTO LOGS(DIR_ID, SIZE, OPEN_DATE) VALUES(%1, \"%2\", \"%3\");")
                                .arg(dirID).arg(size).arg(date);
    if (!query.exec(insert)) throw -3;
}

int DbHelper::GetDirId(QString dir){
    QSqlQuery query;
    QString selectDirs = QString("SELECT ID FROM DIRECTORIES WHERE PATH LIKE (\"%1\");").arg(dir);
    if(!query.exec(selectDirs)) throw -3;
    query.next();
    int dirID = query.value(0).toInt();
    if(dirID == 0){
        QString insert = QString("INSERT INTO DIRECTORIES(PATH) VALUES(\"%1\");").arg(dir);
        query.exec(insert);
        if(!query.exec(selectDirs)) throw -3;
        query.next();
        dirID = query.value(0).toInt();
    }
    return dirID;
}

vector<DirLogRow> DbHelper::ReadLog(){
    auto logs = new vector<DirLogRow>();

    QString select = "SELECT path, size, open_date "
                     "FROM DIRECTORIES JOIN LOGS "
                     "ON DIRECTORIES.ID = LOGS.DIR_ID;";
    QSqlQuery query;
    if(!query.exec(select)) throw -3;
    while(query.next()){
        auto log = new DirLogRow(query.value(0).toString(), query.value(1).toString(), query.value(2).toString());
        logs->push_back(*log);
    }

    return *logs;
}

DbHelper::~DbHelper(){
    _database.close();
}
