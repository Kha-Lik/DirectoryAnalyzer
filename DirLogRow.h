#ifndef DIRLOGROW_H
#define DIRLOGROW_H

#include <QString>
#include <QDate>

class DirLogRow{
    public:
        QString DirectoryName;
        QString Size;
        QDate OpenDate;

        DirLogRow(QString directory, QString size, QDate openDate);
};

#endif // DIRLOGROW_H
