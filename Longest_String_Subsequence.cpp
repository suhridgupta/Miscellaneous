//Program to find the longest common subsequence between two strings

#include <iostream>
#include <vector>

#define MAX(X,Y) (X>Y?X:Y)

using namespace std;

int Longest_Subsequence(string a,string b,int m,int n){
    vector< vector<int> >L(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(a[i-1] == b[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = MAX(L[i-1][j],L[i][j-1]);
        }
    }
    return L[m][n];
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int m,n;
        string a,b;
        cin>>m>>n;
        cin>>a>>b;
        cout<<Longest_Subsequence(a,b,m,n)<<endl;
    }
    return 0;
}