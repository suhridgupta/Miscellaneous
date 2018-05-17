#include <iostream>
#include <vector>

using namespace std;

int subArray(const vector<int>&arr,int K){
    vector<int>cumulative_sum(arr.size());
    cumulative_sum[0] = arr[0];
    for(int i=1;i<arr.size();i++)
        cumulative_sum[i] = cumulative_sum[i-1] + arr[i];
    float max_sum = cumulative_sum[K-1];
    int max_pos = K-1;
    for(int i=K;i<arr.size();i++){
        float current_sum = cumulative_sum[i] - cumulative_sum[i-K];
        if(current_sum > max_sum){
            max_sum = current_sum;
            max_pos = i;
        }
    }
    return max_pos - (K - 1) ;
}

int main(){
    int N,K;
    cin>>N;
    vector<int>arr(N);
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
        cin>>*i;
    cin>>K;
    cout<<subArray(arr,K)<<endl;
    return 0;
}