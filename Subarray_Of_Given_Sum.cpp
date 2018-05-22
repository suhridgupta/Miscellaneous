#include <iostream>
#include <vector>

#define MAX(X,Y) (X>Y?X:Y)

using namespace std;

void subSetSum(const vector<int>&arr,int sum){
    int n = arr.size();
    int current_sum = arr[0];
    int start = 0;
    for(int i=1;i<=n;i++){
        while(current_sum > sum && start < i-1)
            current_sum = current_sum - arr[start++];
        if(current_sum == sum){
            cout<<start+1<<'\t'<<i<<endl;
            return;
        }
        if(i<n)
            current_sum +=arr[i];
    }
    cout<<"-1"<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,s;
        cin>>n>>s;
        vector<int>arr(n);    
        for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
            cin>>*i;
        subSetSum(arr,s);
    }
    return 0;
}