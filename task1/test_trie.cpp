#include <gtest/gtest.h>
#include "Trie.h"

TEST(TrieTest, InsertSingleWord) {
    Trie trie;
    trie.insert("hello");
    ASSERT_TRUE(trie.contains("hello"));
}

TEST(TrieTest, IsEmptyTrie) {
    Trie trie;
    ASSERT_TRUE(trie.empty());
    ASSERT_FALSE(trie.contains("hello"));
    ASSERT_EQ(0, trie.size());
}

TEST(TrieTest, RepeatedInsertion) {
    Trie trie;
    trie.insert("hello");
    trie.insert("hello");
    ASSERT_EQ(1, trie.size());
}

TEST(TrieTest, EraseWord) {
    Trie trie;
    trie.insert("hello");
    trie.erase("hello");
    ASSERT_EQ(0, trie.size());
    ASSERT_FALSE(trie.contains("hello"));
}

TEST(TrieTest, PrefixCount) {
    Trie trie;
    trie.insert("hello");
    trie.insert("head");
    ASSERT_EQ(2, trie.prefix_count("he"));
}

TEST(TrieTest, EmptyStrings) {
    Trie trie;
    trie.insert("");
    ASSERT_TRUE(trie.contains(""));
    ASSERT_EQ(1, trie.size());
    trie.erase("");
    ASSERT_FALSE(trie.contains(""));
}

TEST(TrieTest, EraseSharedPrefix) {
    Trie trie;
    trie.insert("hello");
    trie.insert("head");
    trie.erase("hello");
    ASSERT_FALSE(trie.contains("hello"));
    ASSERT_TRUE(trie.contains("head"));
}

TEST(TrieTest, EraseNonExistentWord) {
    Trie trie;
    trie.insert("hello");
    trie.insert("head");
    ASSERT_FALSE(trie.erase("cat"));
}

TEST(TrieTest, CopyConstructor) {
    Trie trie1;
    trie1.insert("hello");
    trie1.insert("head");
    Trie trie2 = trie1;
    trie2.erase("hello");
    ASSERT_TRUE(trie1.contains("hello"));
}

TEST(TrieTest, MoveConstructor) {
    Trie trie1;
    trie1.insert("hello");
    trie1.insert("head");
    Trie trie2 = std::move(trie1);
    ASSERT_EQ(0, trie1.size());
    ASSERT_TRUE(trie2.contains("hello"));
    ASSERT_EQ(2, trie2.size());
}

TEST(TrieTest, WordsWithPrefix) {
    Trie trie;
    trie.insert("hello");
    trie.insert("head");
    trie.insert("heap");
    std::vector<std::string> expected = {"head", "heap", "hello"};
    ASSERT_EQ(expected, trie.words_with_prefix("he"));
}

TEST(TrieTest, WordsWithPrefixLimit) {
    Trie trie;
    trie.insert("hello");
    trie.insert("head");
    trie.insert("heap");
    std::vector<std::string> expected = {"head", "heap"};
    ASSERT_EQ(expected, trie.words_with_prefix("he", 2));
}

TEST(TrieTest, EqualityOperator) {
    Trie trie1, trie2;
    trie1.insert("hello");
    trie1.insert("head");
    trie2.insert("head");
    trie2.insert("hello");
    ASSERT_TRUE(trie1 == trie2);
}