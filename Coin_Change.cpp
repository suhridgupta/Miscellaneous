//Program to calculate the number of ways a set of coins S[] can form a sum N. Each coin can be used infinitely
#include <iostream>
#include <vector>

using namespace std;

int coinChange(const vector<int>&coins,int N){
    int size = coins.size();
    vector< vector<int> >permutation(N+1,vector<int>(size));
    
    for(int i=0;i<size;i++)
        permutation[0][i] = 1; //Base case, phi
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<size;j++){
            int exclude = (j-1)>=0?permutation[i][j-1]:0; //Excluding the new coin
            int include = (i-coins[j])>=0?permutation[i-coins[j]][j]:0; //Including the new coin
            permutation[i][j] = include + exclude;
        }
    }
    return permutation[N][size-1];
}

int main(){
    int size,N;
    cin>>size;
    vector<int>coins(size);
    for(vector<int>::iterator i=coins.begin();i!=coins.end();i++)
        cin>>*i;
    cin>>N;
    cout<<coinChange(coins,N)<<endl;
    return 0;
}