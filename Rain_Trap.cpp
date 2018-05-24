#include <iostream>
#include <vector>

#define MAX(X,Y) (X>Y?X:Y)
#define MIN(X,Y) (X<Y?X:Y)

using namespace std;

int rainTrap(const vector<int>&arr){
    int n = arr.size(),water = 0;
    vector<int>left(n),right(n);
    left[0] = arr[0];
    for(int i=1;i<n;i++)
        left[i] = MAX(left[i-1],arr[i]);
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--) 
        right[i] = MAX(right[i+1],arr[i]);
    for(int i=0;i<n;i++)
        water += MIN(left[i],right[i]) - arr[i];
    return water;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++)
        cin>>*i;
    cout<<rainTrap(arr)<<endl;
    return 0;
}