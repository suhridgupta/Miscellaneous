//Program to find sum of bit differences in all pairs of 32 bit integers that can be formed from array elements

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,sum=0;
	    cin>>n;
	    vector<long long int>arr(n);
	    for(long long int i=0;i<n;i++)
	        cin>>arr[i];
        //traverse all the 32 bits
        for(long long int i=0;i<32;i++){
            //Stores the number of set bits in position i
            long long int count = 0;
            for(long long int j=0;j<n;j++){
                if(arr[j] & (1<<i))
                    count++;
            }
            //count*(n-count) stores the number of pairs with different bits
            //2*value is for both pairs (x,y) and (y,x)
            sum+=(2*count*(n-count));
        }
        cout<<sum<<endl;
	}
	return 0;
}