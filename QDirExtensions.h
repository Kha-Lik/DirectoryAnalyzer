#ifndef QDIREXTENSIONS_H
#define QDIREXTENSIONS_H

#include <QWidget>

 class QDirExtensions {
    public:
        static qint64 dirSize(QString dirPath);
        static QString formatSize(qint64 size);
};

#endif // QDIREXTENSIONS_H
