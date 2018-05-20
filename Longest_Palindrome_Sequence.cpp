//Modification of Longest String Subsequence
#include <iostream>
#include <vector>

#define MAX(X,Y) (X>Y?X:Y)

using namespace std;

int longestPalindrome(string a){
    int m = a.length();
    vector< vector<int> >sequence(m+1,vector<int>(m+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            if(i == 0 || j == 0)
                sequence[i][j] = 0;
            else if(a[i-1] == a[m-j])
                sequence[i][j] = sequence[i-1][j-1] + 1;
            else
                sequence[i][j] = MAX(sequence[i-1][j],sequence[i][j-1]);
        }
    }
    return sequence[m][m];
}

int main(){
    string a;
    cin>>a;
    cout<<longestPalindrome(a)<<endl;
    return 0;
}