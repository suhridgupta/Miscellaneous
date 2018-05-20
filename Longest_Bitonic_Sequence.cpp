//Program to find the longest bitonic sequence in a given array
#include <iostream>
#include <vector>

using namespace std;

int findMax(const vector<int>&arr,int value,int len){
    int max = 0,pos = -1;
    for(int i=0;i<len;i++){
        if(max<arr[i] && value>arr[i]){
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}

int findMin(const vector<int>&arr,int value,int start){
    int max = 0,pos = -1;
    for(int i=arr.size()-1;i>start;i--){
        if(max<arr[i] && value>arr[i]){
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}

int longestBitonic(const vector<int>&arr){
    int n = arr.size(),max = 0;
    vector<int>lis(n+1),lds(n+1);
    lis[0] = 0;
    lds[n] = 0;
    for(int i=0;i<n;i++){
        int pos_lis = findMax(arr,arr[i],i);
        int pos_lds = findMin(arr,arr[n-i-1],n-i-1);
        if(pos_lis == -1)
            lis[i+1] = 1;
        else
            lis[i+1] = lis[pos_lis+1] + 1;
        if(pos_lds == -1)
            lds[n-i-1] = 1;
        else
            lds[n-i-1] = lds[pos_lds] + 1;
    }
    for(int i=1;i<=n;i++)
        if(lds[i-1]+lis[i]-1>max)
            max = lds[i-1]+lis[i]-1;
    return max;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
        cin>>*i;
    cout<<longestBitonic(arr)<<endl;
    return 0;
}