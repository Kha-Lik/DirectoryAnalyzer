#ifndef DIRLOGROW_H
#define DIRLOGROW_H

#include <QString>
#include <QDate>

class DirLogRow{
    public:
        QString DirectoryName;
        QString Size;
        QString OpenDate;

        DirLogRow(QString directory, QString size, QString openDate);
};

#endif // DIRLOGROW_H
