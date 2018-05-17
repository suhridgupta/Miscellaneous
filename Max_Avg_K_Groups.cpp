#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float KGroupSum(vector<int>&arr,int K){
    float sum = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-K+1;i++)
        sum = sum + arr[i];
    cout<<sum<<endl;
    sum = sum / (arr.size() - K + 1);
    for(int i=arr.size()-K+1;i<arr.size();i++)
        sum = sum + arr[i];
    return sum;
}

int main(){
    int N,K;
    cin>>N;
    vector<int>arr(N);
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
        cin>>*i;
    cin>>K;
    cout<<KGroupSum(arr,K);
}