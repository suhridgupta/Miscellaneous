//Program to find the minimum edit,replace,insert ops required to convert one string into another
#include <iostream>
#include <vector>

#define MIN(X,Y) (X<Y?X:Y)

using namespace std;

int editDistance(string a, string b){
    int m = a.length(),n = b.length();
    vector< vector<int> >dist(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0)
                dist[i][j] = j;
            else if(j == 0)
                dist[i][j] = i;
            else if(a[i-1] == b[j-1])
                dist[i][j] = dist[i-1][j-1];
            else
                dist[i][j] = MIN(MIN(dist[i-1][j],dist[i][j-1]),dist[i-1][j-1]) + 1;
        }
    }
    return dist[m][n];
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<editDistance(a,b)<<endl;
    return 0;
}