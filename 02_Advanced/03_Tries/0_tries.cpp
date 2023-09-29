#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
  bool word = false;
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {

    TrieNode *curr = root;

    for (char ch : word) {

      if (curr->children.count(ch) == 0)
        curr->children[ch] = new TrieNode();

      curr = curr->children[ch];
    }

    curr->word = true;
  }

  bool search(string word) {
    TrieNode *curr = root;

    for (char ch : word) {

      if (curr->children.count(ch) == 0)
        return false;

      curr = curr->children[ch];
    }

    return curr->word;
  }

  bool startsWith(string prefix) {
    TrieNode *curr = root;

    for (char ch : prefix) {

      if (curr->children.count(ch) == 0)
        return false;

      curr = curr->children[ch];
    }

    return true;
  }
};

int main() {
  /*
  https://leetcode.com/problems/implement-trie-prefix-tree/
  https://leetcode.com/problems/design-add-and-search-words-data-structure/
  https://leetcode.com/problems/word-search-ii/
  https://leetcode.com/problems/prefix-and-suffix-search/
  */
}
