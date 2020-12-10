#include <DirLogRow.h>

DirLogRow::DirLogRow(QString directory, QString size, QDate openDate){
    DirectoryName = directory;
    Size = size;
    OpenDate = openDate;
}
