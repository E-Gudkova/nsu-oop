#ifndef OOP_CSVWRITER_H
#define OOP_CSVWRITER_H
#include <string>
#include <map>
#include <list>
#include <utility>
#include <fstream>

class CsvWriter {
public:
    void write(const std::map<std::string, int> &counts,
               int totalWords,
               std::ofstream &out);

    ~CsvWriter();
};
#endif //OOP_CSVWRITER_H
