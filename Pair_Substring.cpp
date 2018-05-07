#include <iostream>
#include <stdlib.h>

using namespace std;

#define char2Int(x) ((int)x-(int)'a')

struct trie{
    trie *next[26];
    bool isLeaf;
};

trie *newNode(){
    trie *newTrie = (trie*)malloc(sizeof(trie));
    for(int i=0;i<26;i++)
        newTrie->next[i] = nullptr;
    newTrie->isLeaf = false;
    return newTrie;
}

trie *insertNode(trie *root,string word){
    trie *temp = root;
    for(int i=0;i<word.length();i++){
        if(temp->next[char2Int(word[i])] == nullptr)
            temp->next[char2Int(word[i])] = newNode();
        temp = temp->next[char2Int(word[i])];
    }
    temp->isLeaf = true;
    return root;
}

int searchTrie(trie *root,string word){
    int len = 0;
    for(int i=0;i<word.length();i++){
        if(root->next[char2Int(word[i])] == nullptr){
            if(root->isLeaf)
                return len;
            return -1;
        }
        root = root->next[char2Int(word[i])];
        len++;
    }
    if(root->isLeaf)
        return len;
    return -1;
}

int findPair(trie *root,string word){
    int len = searchTrie(root,word);
    if(len == 0)
        return 0;
    string partition(word,len,word.length()-len);
    len = searchTrie(root,partition);
    return (len>0);
}

int main(){
    trie *root = newNode();
    root = insertNode(root,"hello");
    root = insertNode(root,"my");
    root = insertNode(root,"world");
    root = insertNode(root,"name");
    string word = "helloworld";
    cout<<findPair(root,word)<<endl;
    return 0;
}