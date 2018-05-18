//Program to find the longest increasing sequence of numbers in an array
#include <iostream>
#include <vector>

using namespace std;

int found(const vector<int>&arr,int value,int len){
    int pos = -1,max=-9999;
    for(int i=len;i>=0;i--)
        if(arr[i] < value && max < arr[i]){
            pos = i;
            max = arr[i];
        }
    return pos;
}

int longestSequence(const vector<int>&arr){
    int n = arr.size(),max_dist = 0;
    vector<int>dist(n+1);
    dist[0] = 0;
    for(int i=0;i<n;i++){
        int pos=found(arr,arr[i],i);
        if(pos != -1)
            dist[i+1] = dist[pos+1] + 1;
        else
            dist[i+1] = 1;
        if(dist[i+1]>max_dist)
            max_dist = dist[i+1];
    }
    return max_dist;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++){
        cin>>*i;
    }
    cout<<longestSequence(arr)<<endl;
    return 0;
}