#include<iostream>
#include "tire.cpp"
using namespace std;
int main(){
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("banana");
    trie.insert("bar");

    cout << trie.search("apple") << endl;

    trie.displayAllWords();

    return 0;
}
