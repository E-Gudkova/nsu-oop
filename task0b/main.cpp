#include "WordCounter.h"
#include <fstream>
#include <sstream>
#include <iostream>

#include "CsvWriter.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Error! Expected 3 arguments" << "\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    std::ifstream in(inputFile);
    std::ofstream out(outputFile);

    if (!in.is_open()) {
        std::cout << "File:" << inputFile << " didn't open" << "\n";
        return 1;
    }

    if (!out.is_open()) {
        std::cout << "File:" << outputFile << " didn't open" << "\n";
        return 1;
    }

    WordCounter counter;
    std::string line;

    while (std::getline(in, line)) {
        counter.addLine(line);
    }
    CsvWriter writer;
    writer.write(counter.getCounts(), counter.getTotalWords(), out);

    return 0;
}
