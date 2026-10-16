#include "WordCounter.h"
#include <cctype>

void WordCounter::addLine(const std::string &line) {
    std::string word;

    for (char c: line) {
        if (std::isalnum(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                ++counts_[word];
                ++totalWords_;
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        ++counts_[word];
        ++totalWords_;
    }
}

const std::map<std::string, int> &WordCounter::getCounts() const {
    return counts_;
}

int WordCounter::getTotalWords() const {
    return totalWords_;
}

double WordCounter::getPercent(int count, int totalWords) {
    if (totalWords == 0) {
        return 0.0;
    }
    return (100.0 * count) / totalWords;
}


std::list<std::pair<std::string, int> > WordCounter::sortedByFrequency() const {
    std::list<std::pair<std::string, int>> items(counts_.begin(), counts_.end());

    items.sort([](const auto &a, const auto &b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    return items;
}

