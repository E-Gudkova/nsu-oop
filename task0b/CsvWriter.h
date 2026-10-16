#ifndef OOP_CSVWRITER_H
#define OOP_CSVWRITER_H
#include <string>
#include <map>
#include <list>
#include <utility>
#include <fstream>

class CsvWriter {
public:
     static void write(const std::list<std::pair<std::string, int>>& items,
                int totalWords,
               const std::string& header,
               std::ofstream &out);

};
#endif //OOP_CSVWRITER_H
