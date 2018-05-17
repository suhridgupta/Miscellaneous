//Program to find the minimum number of steps required to create a string using append and duplicate operations
#include <iostream>
#include <vector>

#define MIN(X,Y) (X<Y?X:Y)

using namespace std;

int minimalMoves(string s){
    vector<int>moves(s.length()+1,9999);
    string s1 = "",s2 = "";
    s1 = s[0];
    moves[0] = 1;
    for(int i=1;i<s.length();i++){
        s1 = s1 + s[i];
        moves[i] = MIN(moves[i],moves[i-1]+1);
        s2 = s.substr(i+1,i+1); //Check in front for a duplicate
        if(s2 == s1)
            moves[i*2+1] = MIN(moves[i*2+1],moves[i]+1);
    }
    return moves[s.length()-1];
}

int main(){
    string s;
    cin>>s;
    cout<<minimalMoves(s);
    return 0;
}