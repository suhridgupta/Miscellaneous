//Program to find the minimum partitions required to make each partition a palindrome

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MIN(X,Y) (X<Y?X:Y)

using namespace std;

int calcPartitions(string word){
    int n = word.size();
    vector< vector<bool> >palindrome(n,vector<bool>(n));
    vector< vector<int> >partitions(n,vector<int>(n));
    //Set value of substrings of length 1
    for(int i=0;i<n;i++){
        palindrome[i][i] = true; //each letter is a palindrome so number of partitions is 0
        partitions[i][i] = 0;
    }
    //Iterate through all substrings of length 2-n
    for(int L=2;L<=n;L++){
        for(int i=0;i<n-L+1;i++){
            int j = i+L-1;
            if(L == 2){ //If its a two letter word, compare the two letters
                palindrome[i][j] = (word[i] == word[j]); 
            }
            else{ //Check corner characters as well as middle ones (p[i+1][j-1])
                palindrome[i][j] = (word[i] == word[j]) && palindrome[i+1][j-1];
            }
            if(palindrome[i][j]){
                partitions[i][j] = 0; //No partitions required
            }
            else{ //Iterate all partitions from i to j
                partitions[i][j] = 9999;
                for(int k=i;k<j;k++){
                    partitions[i][j] = MIN(partitions[i][j],partitions[i][k]+partitions[k+1][j]+1);
                }
            }
        }
    }
    return partitions[0][n-1]; //Value is stored in the last column of the first row
}

int main(){
    string word;
    cin>>word;
    cout<<"Number of partitions: "<<calcPartitions(word)<<endl;
    return 0;
}