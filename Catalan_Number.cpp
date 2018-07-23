#include <iostream>

using namespace std;

int catalanNumber(const int n){
    int res = 1;
    for(int i=0;i<n;i++){
        res*=(2*n-i);
        res/=(i+1);
    }
    return res/(1+n);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        cout<<catalanNumber(i)<<'\t';
    cout<<endl;
    return 0;
}