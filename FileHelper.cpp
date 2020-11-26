#include "FileHelper.h"
#include <QFile>
#include <QString>
#include <QTextStream>

using namespace::std;

void FileHelper::writeStringToFile(std::string str, std::string path){
     QFile saveFile(QString::fromStdString(path));

     if(saveFile.open(QIODevice::Append | QIODevice::Text)){
         QTextStream out(&saveFile);
         out << QString::fromStdString(str) << Qt::endl;
         saveFile.close();
     }
     else{
         throw -1;
     }
}

vector<string> FileHelper::readAllLines(string path){
    QFile saveFile(QString::fromStdString(path));
    vector<string> content;

    if(saveFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&saveFile);

        while (!in.atEnd()) {
            content.push_back(in.readLine().toStdString());
        }

        saveFile.close();
    }
    else{
        throw -1;
    }
    return content;
}

vector<string> FileHelper::readRangeOfLines(int start, int end, string path){
    QFile saveFile(QString::fromStdString(path));
    vector<string> content;

    if(saveFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&saveFile);

        int counter = 0;
        while (!in.atEnd()) {
            ++counter;
            if (counter >= start && counter <= end)
                content.push_back(in.readLine().toStdString());
            if (counter > end) break;
        }
        saveFile.close();
    }
    else{
        throw -1;
    }
    return content;
}
