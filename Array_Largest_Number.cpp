#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool comp(const int &a,const int &b){
    int size_a,size_b;
    size_a = a>1?(int)floor(log10(a)+1):1;
    size_b = b>1?(int)floor(log10(b)+1):1;
    size_a = (int)pow(10,size_a);
    size_b = (int)pow(10,size_b);
    int x = a*size_b+b;
    int y = b*size_a+a;
    return x>y;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    vector<int>arr(n);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        sort(arr.begin(),arr.end(),comp);
        for(int i=0;i<n;i++)
            cout<<arr[i];
        cout<<endl;
	}
	return 0;
}