#include "Trie.h"
#include <utility>


Trie::Trie() {
    root = new Node();
    wordCount = 0;
}
Trie::~Trie() {
    deleteTree(root);
}

Trie::size_type Trie::size() const {
    return wordCount;
}

bool Trie::empty() const {
    return wordCount == 0;
}


Trie::Node* Trie::copyNode(const Node* otherNode) const{
    if (otherNode == nullptr) return nullptr;
    Node* newNode = new Node();
    newNode->isEnd = otherNode->isEnd;

    for (const auto& pair: otherNode->children) {
        newNode->children[pair.first] = copyNode(pair.second);
    }
    return newNode;
}


void Trie::deleteTree(Node* node) {
    if (node == nullptr) return;

    for (const auto& pair: node->children) {
        deleteTree(pair.second);
    }
    delete node;
}

void Trie::clear() {
    deleteTree(root);
    root = new Node();
    wordCount = 0;
}


Trie::Trie(const Trie& other) {
    root = copyNode(other.root);
    wordCount = other.wordCount;
}

Trie& Trie::operator=(const Trie& other) {
    if (this != &other) {
        clear();
        root = copyNode(other.root);
        wordCount = other.wordCount;
    }
    return *this;
}

void Trie::insert(const std::string_view word) {
    Node* current = root;
    for (char c: word) {
        if (!(current-> children.contains(c))) {
            current->children[c] = new Node();
        }
        current = current->children[c];
    }
    if (!current->isEnd) {
        current->isEnd = true;
        ++wordCount;
    }
}

bool Trie::contains(std::string_view word) const {
    const Node* current = root;
    for (char c: word) {
        if (!current-> children.contains(c)) {
            return false;
        }
        current = current->children.at(c);
    }
    if (current->isEnd == true) {
        return true;
    }
    return false;
}

Trie::size_type Trie::countWords(const Node* node) const {
    size_type count=0;
    if (node == nullptr) return 0;
    if (node->isEnd) {
        count = 1;
    }else {
        count = 0;
    }
    for (const auto& pair: node->children) {
        count += countWords(pair.second);
    }
    return count;
}

Trie::size_type Trie::prefix_count(std::string_view pref) const {
    const Node* current = root;
    for (char c: pref) {
        if (!current-> children.contains(c)) {
            return 0;
        }
        current = current->children.at(c);
    }
    return countWords(current);
}

void Trie::collectWords(const Node *node, std::string current_word, std::vector<std::string> &result, size_type limit) const {
    if (node == nullptr) return;
    if (limit > 0 and limit==result.size()) {
        return;
    }
    if (node->isEnd) {
        result.push_back(current_word);
    }
    for (const auto& pair: node->children) {
        collectWords(pair.second, current_word + pair.first, result, limit);
    }
}

std::vector<std::string> Trie::words_with_prefix(std::string_view pref, size_type limit) const {
    std::vector<std::string> result;
    const Node* current = root;
    for (char c: pref) {
        if (!current->children.contains(c)) {
            return result;
        }
        current = current->children.at(c);
    }
    collectWords(current, std::string(pref), result, limit);
    return result;
}

bool Trie::erase(std::string_view word) {
    if (!contains(word)) return false;
    std::vector<std::pair<Node*, char>> path;
    Node* current = root;
    for (char c: word) {
        path.push_back({current, c});
        current = current->children[c];
    }
    current->isEnd = false;
    wordCount--;
    for (int i = path.size() - 1; i >= 0; i--) {
        Node* child = path[i].first->children[path[i].second];
        if (!child->isEnd && child->children.empty()) {
            delete child;
            path[i].first->children.erase(path[i].second);
        }else break;
    }
    return true;
}


bool Trie::operator==(const Trie &other) const {
    return words_with_prefix("") == other.words_with_prefix("");
}



Trie::Trie(Trie&& other) noexcept {
    root = other.root;
    wordCount = other.wordCount;
    other.root = nullptr;
    other.wordCount = 0;
}

Trie& Trie::operator=(Trie&& other) noexcept {
    if (this != &other) {
        clear();
        root = other.root;
        wordCount = other.wordCount;
        other.root = nullptr;
    }
    return *this;
}

bool Trie::operator!=(const Trie &other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Trie& trie) {
    auto all_words = trie.words_with_prefix("");
    for (const auto& word: all_words) {
        os << word << "\n";
    }
    return os;
}
