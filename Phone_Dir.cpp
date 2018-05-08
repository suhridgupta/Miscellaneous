#include <iostream>
#include <vector>

#define char2Int(X) ((int)X - int('a'))

using namespace std;

struct trie{
    bool isLeaf;
    trie *next[26];
};

trie *newNode(){
    trie *node = (trie*)malloc(sizeof(trie));
    node->isLeaf = false;
    for(int i=0;i<26;i++)
        node->next[i] = nullptr;
    return node;
}

trie *insert(trie *root,string word){
    trie *temp = root;
    for(int i=0;i<word.length();i++){
        if(temp->next[char2Int(word[i])] == nullptr)
            temp->next[char2Int(word[i])] = newNode();
        temp = temp->next[char2Int(word[i])];
    }
    temp->isLeaf = true;
    return root;
}

void display(trie *root,string word){
    if(root->isLeaf){
        cout<<word<<'\t';
    }
    else{
        for(int i=0;i<26;i++){
            if(root->next[i]){
                word = word+(char)(i+'a');
                display(root->next[i],word);
                word = word.substr(0,word.size()-1);
            }
        }
    }
}

trie *Search(trie *root,string word){
    trie *temp = root;
    for(int i=0;i<word.length();i++){
        if(temp->next[char2Int(word[i])] == nullptr){
            cout<<"0";
            return root;
        }
        temp = temp->next[char2Int(word[i])];
    }
    display(temp,word);
    return root;
}

int main(){
    trie *root = newNode();
    int N,T;
    cin>>T;
    for(int z=0;z<T;z++){
        cin>>N;
        vector<string>contacts(N);
        string search;
        for(int i=0;i<N;i++){
            cin>>contacts[i];
        }
        cin>>search;
        for(vector<string>::iterator i = contacts.begin();i!=contacts.end();i++)
            root = insert(root,*i);
        for(int i=1;i<=search.length();i++){
            string sub = search.substr(0,i);
            root = Search(root,sub);
            cout<<endl;
        }
    }
    return 0;
}