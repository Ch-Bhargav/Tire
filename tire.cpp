#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndWord;

    TrieNode() : isEndWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    void displayAllWords(TrieNode* node, string currentWord, vector<string>& words) {
        if (node->isEndWord) {
            words.push_back(currentWord);
        }
        for (const auto& child : node->children) {
            displayAllWords(child.second, currentWord + child.first, words);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndWord = true;
    }

    bool search(const string& word) const {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndWord;
    }

    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

    void displayAllWords() {
        vector<string> words;
        displayAllWords(root, "", words);
        cout << "Words in the Trie Data Structure:" << endl;
        for (const string& word : words) {
            cout << word << endl;
        }
    }
};
