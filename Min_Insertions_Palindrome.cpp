#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(X,Y) (X>Y?X:Y)

using namespace std;

int palindromeInsert(string a){
    int n = a.length();
    string b = a;
    reverse(b.begin(),b.end());
    vector< vector<int> >ins(n+1,vector<int>(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0)
                ins[i][j] = 0;
            else if(a[i-1] == b[j-1])
                ins[i][j] = ins[i-1][j-1] + 1;
            else
                ins[i][j] = MAX(ins[i-1][j],ins[i][j-1]);
        }
    }
    return n-ins[n][n];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    string a;
	    cin>>a;
	    cout<<palindromeInsert(a)<<endl;
	}
	return 0;
}