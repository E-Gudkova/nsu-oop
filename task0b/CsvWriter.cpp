#include "CsvWriter.h"
#include <list>


void CsvWriter::write(const std::map<std::string, int> &counts,
                      int totalWords,
                      std::ofstream &out) {
    std::list<std::pair<std::string, int> > items;
    for (const auto &pair: counts) {
        items.push_back(pair);
    }
    items.sort([](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    out << "Слово,Частота,Частота (%)\n";
    for (const auto &item: items) {
        double percent = 100.0 * item.second / totalWords;
        out << item.first << "," << item.second << "," << percent << "\n";
    }
}

CsvWriter::~CsvWriter() {
}
