#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isWord = false;
    unordered_map<char, TrieNode*> child;
};

class Trie {
private:
    TrieNode *root = new TrieNode();

public:
    Trie() {}

    void insert(string word) {
        TrieNode *t = root;
        for(char ch: word) {
            if(t->child.count(ch) == 0) t->child[ch] = new TrieNode();
            t = t->child[ch];
        }
        t->isWord = true;
    }

    bool searchWord(string word) {
        TrieNode *t = root;
        for(char ch: word) {
            if(t->child.count(ch) == 0) return false;
            t = t->child[ch];
        }
        return t->isWord;
    }

    bool searchPrefix(string word) {
        TrieNode *t = root;
        for(char ch: word) {
            if(t->child.count(ch) == 0) return false;
            t = t->child[ch];
        }
        return true;
    }
};

int main() {
    
    Trie trie;
    trie.insert("apple");
    cout << trie.searchWord("apple") << endl;   // Output: 1 (true)
    cout << trie.searchWord("app") << endl;     // Output: 0 (false)
    cout << trie.searchPrefix("app") << endl;   // Output: 1 (true)
    trie.insert("app");
    cout << trie.searchWord("app") << endl;     // Output: 1 (true)
}