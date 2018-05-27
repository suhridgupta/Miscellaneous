#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool>prime(n+1,true);
    for(int i=2;i<sqrt(n+1);i++){
        for(int j=i*i;j<=n;j=j+i)
            prime[j] = false;
    }
    for(int i=0;i<=n;i++)
        if(prime[i])    
            cout<<i<<' ';
    cout<<endl;
    return 0;
}