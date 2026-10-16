#include "CsvWriter.h"
#include <list>

#include "WordCounter.h"


void CsvWriter::write(const std::list<std::pair<std::string, int> > &items,
                      int totalWords,
                      const std::string& header,
                      std::ofstream &out) {
    out << header << "\n";
    for (const auto &item: items) {
        double percent = WordCounter::getPercent(item.second, totalWords);
        out << item.first << "," << item.second << "," << percent << "\n";
    }
}
