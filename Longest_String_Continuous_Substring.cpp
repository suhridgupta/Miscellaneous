#include <iostream>
#include <vector>

using namespace std;

void longestSubstring(string a,string b){
    int m = a.length(),n=b.length(),max = 0;
    vector< vector<int> >len(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0)
            len[i][j] = 0;
            else if(a[i-1] == b[j-1]){
                len[i][j] = len[i-1][j-1] + 1;
                if(len[i][j]>max){
                    max = len[i][j];
                }
            }
            else
                len[i][j] = 0;
        }
    }
    cout<<max<<endl;
}

int main(){
    string a,b;
    cin>>a>>b;
    longestSubstring(a,b);
    return 0;
}