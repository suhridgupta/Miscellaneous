//Program to find the longest continuous palindromic substring
#include <iostream>
#include <vector>

using namespace std;

int palindromeSubstring(string a){
    int n = a.size();
    int max_len = 1;
    vector< vector<bool> >pal(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        pal[i][i] = true; //string of length 1 always palindrome
    }
    for(int i=0;i<n-1;i++){
        if(a[i] == a[i+1]){
            pal[i][i+1] = true;
            max_len = 2;
        }
    }
    for(int l=3;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j = i+l-1;
            if(pal[i+1][j-1] && a[i] == a[j]){
                pal[i][j] = true;
                if(l>max_len)
                    max_len = l;
            }
        }
    }
    return max_len;
}

int main(){
    string a;
    cin>>a;
    cout<<palindromeSubstring(a)<<endl;
    return 0;
}