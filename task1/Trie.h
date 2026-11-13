#ifndef OOP_TRIE_H
#define OOP_TRIE_H
#include <map>
#include <string>
#include <vector>
#include <string_view>
#include <iostream>
#include <cstddef>


class Trie {
public:
    using size_type = std::size_t;

    Trie();
    ~Trie();

    Trie(const Trie &);
    Trie(Trie&& other) noexcept;

    Trie& operator = (const Trie& other);
    Trie& operator = (Trie&& other) noexcept;

    bool empty() const;
    size_type size() const;

    void clear();
    void insert(std::string_view word);
    bool contains(std::string_view word) const;
    bool erase(std::string_view word);

    bool operator==(const Trie& other) const;
    bool operator!=(const Trie& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Trie& trie);

    size_type prefix_count(std::string_view pref) const;
    std::vector<std::string> words_with_prefix(std::string_view pref, size_type limit = 0) const;

private:
    struct Node {
        bool isEnd = false;
        std::map<char, Node*> children;
    };

    Node* root = nullptr;
    size_type wordCount = 0;
    Node* copyNode(const Node* other) const;
    void deleteTree(Node* node);
    size_type countWords(const Node* node) const;
    void collectWords(const Node* node, std::string current_word, std::vector<std::string>& result, size_type limit) const;
};


#endif //OOP_TRIE_H