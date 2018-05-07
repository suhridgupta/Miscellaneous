#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myFunc(const int i,const int j){
    return i<j;
}

int findPair(vector<int>&arr,int x){
    int l = 0;
    int r = arr.size()-1;
    while(l<r){
        int sum = arr[l]+arr[r];
        if(sum == x){
            cout<<arr[l]<<'\t'<<arr[r]<<endl;
            return 1;
        }  
        if(sum>x)
            r--;
        else
            l++;
    }
    return 0;
}

int main(){
    int n,x;
    cin>>n;
    vector<int>arr(n);
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
        cin>>*i;
    cin>>x;
    sort(arr.begin(),arr.end(),myFunc);
    int result = findPair(arr,x);
    if(result == 0)
        cout<<"No Pairs Exist\n";
    return 0;
}