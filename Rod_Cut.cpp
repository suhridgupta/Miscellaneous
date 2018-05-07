#include <iostream>
#include <vector>

#define INF 9999
#define MAX(a,b) (a>b?a:b)

using namespace std;

int Max_Rod(const vector<int>&price,int N){
    vector<int>new_price(N+1,0);
    for(int i=1;i<N+1;i++){
        int q = -INF;
        for(int j=1;j<=i;j++)
            q = MAX(q,price[j]+new_price[i-j]);
        new_price[i] = q;
    }
    return new_price[N];
}

int main(){
    int N; //Size of the rod
    cin>>N;
    vector<int>price(N+1,0); //Price for each rod size from 1-N
    for(int i=1;i<N+1;i++){
        cin>>price[i];
    }
    cout<<Max_Rod(price,N)<<endl; //Optimal Price for rod
    return 0;
}