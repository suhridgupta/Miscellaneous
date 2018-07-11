//Program to print all non-repeating subsequences in a string

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void printSubsequence(vector<char>&result,int len){
    if(len==0)
        return;
    for(int i=0;i<len;i++)
        cout<<result[i];
    cout<<endl;
}

void createSubsequence(string letters,vector<int>&count,int pos,vector<char>result,int level){
    printSubsequence(result,level);
    for(int i=pos;i<count.size();i++){
        if(count[i] == 0)
            continue;
        result[level] = letters[i];
        count[i]--;
        createSubsequence(letters,count,i,result,level+1);
        count[i]++;
    }
}

void stringSubsequence(string a){
    map<char,int>num;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        num[a[i]]++;
    }
    string letters = "";
    vector<char>result(a.size());
    vector<int>count;
    for(map<char,int>::iterator i=num.begin();i!=num.end();i++){
        letters+=i->first;
        count.push_back(i->second);
    }
    createSubsequence(letters,count,0,result,0);
}

int main(){
    string a;
    cin>>a;
    stringSubsequence(a);
    return 0;
}