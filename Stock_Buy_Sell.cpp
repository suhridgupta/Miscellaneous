#include <iostream>
#include <vector>

using namespace std;

void pairProfit(const vector<int>&arr){
    int n = arr.size(),flag = 0;
    int a,i=0;
    while(i<n){
        int b = n - 1;
        a = i;
        int rising = arr[a];
        for(int j=a+1;j<n;j++){
            if(arr[j]>rising)
                rising = arr[j];
            else{
                b = j - 1;
                break;
            }
        }
        if(a != b){
            cout<<"("<<a<<" "<<b<<")\n";
            flag = 1;
        }
        i = b + 1;
    }
    if(flag == 0)
        cout<<"No Profit"<<endl;
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
        pairProfit(arr);
	}
	return 0;
}