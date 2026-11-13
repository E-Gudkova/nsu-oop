#include "Trie.h"
#include <iostream>

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("cat");
    trie.insert("car");
    trie.insert("head");

    std::cout << trie << "\n";

    trie.erase("world");
    std::cout << trie << '\n';
    return 0;
}
