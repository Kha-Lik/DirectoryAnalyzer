#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <string>
#include <vector>

class FileHelper {
    public:
        void writeStringToFile(std::string str, std::string path);
        std::vector<std::string> readAllLines(std::string path);
        std::vector<std::string> readRangeOfLines(int start, int stop, std::string path);
};

#endif // FILEHELPER_H
