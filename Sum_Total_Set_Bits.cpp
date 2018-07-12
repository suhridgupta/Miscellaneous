//Program to find the total number of set bits from 1 to N
//Uses gcc function __builtin_popcount()

#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n,sum=0;
	    cin>>n;
	    for(int i=1;i<=n;i++){
	        sum+=__builtin_popcount(i);
	    }
	    cout<<sum<<endl;
	}
	return 0;
}