//Program to find the minimum number of steps required to traverse an array
#include <iostream>
#include <vector>

#define INF 9999
#define MIN(X,Y) (X<Y?X:Y)

using namespace std;

int minJumps(const vector<int>&arr){
    int n = arr.size();
    vector<int>min_path(n,INF);
    min_path[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(j+arr[j]>=i){ //Check if the jump can actually reach i
                min_path[i] = MIN(min_path[i],min_path[j]+1);
            }
        }
    }
    return min_path[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
        cin>>*i;
    cout<<minJumps(arr)<<endl;
    return 0;
}