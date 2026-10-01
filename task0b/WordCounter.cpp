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
