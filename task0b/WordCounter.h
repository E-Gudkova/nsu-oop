#ifndef OOP_WORDCOUNTER_H
#define OOP_WORDCOUNTER_H
#include <string>
#include <map>

class WordCounter {
public:
    void addLine(const std::string &line);

    const std::map<std::string, int> &getCounts() const;

    int getTotalWords() const;

private:
    std::map<std::string, int> counts_;
    int totalWords_ = 0;
};
#endif //OOP_WORDCOUNTER_H
