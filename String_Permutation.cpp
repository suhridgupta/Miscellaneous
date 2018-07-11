//Program to print all string permutations without repetition
//For repetition, next_permutation() can be used

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void printString(vector<char>&result){
    for(int i=0;i<result.size();i++)
        cout<<result[i];
    cout<<endl;
}

void createPermutations(string letter,vector<int>&count,vector<char>&result,int level){
    if(level == result.size()){ //if we reach a recursive level of the result size, print
        printString(result);
        return;
    }
    for(int i=0;i<count.size();i++){ //iterate over each letter count from left to right
        if(count[i] == 0) 
            continue;
        count[i]--;
        result[level] = letter[i]; //append letter
        createPermutations(letter,count,result,level+1); //recursion
        count[i]++; //backtrack
    }
}

void stringPermutation(string a){
    sort(a.begin(),a.end());
    map<char,int>num;
    for(int i=0;i<a.size();i++){
        num[a[i]]++;
    }
    string letters=""; //Used to store each unique letter
    vector<int>count; //Used to store the occurrence of each letter
    for(map<char,int>::iterator i=num.begin();i!=num.end();i++){
        letters+=i->first; //key
        count.push_back(i->second); //value
    }
    vector<char>result(a.size(),' '); //stores each permutation result
    createPermutations(letters,count,result,0);
}

int main(){
    string a;
    cin>>a;
    stringPermutation(a);
}