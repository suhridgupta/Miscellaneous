#include <iostream>
#include <vector>

#define MAX(X,Y) (X>Y?X:Y)

using namespace std;

int Knapsack(const vector<int>&value,const vector<int>&weight,int N,int W){
    vector< vector<int> >K(N+1,vector<int>(W+1));
    for(int i=0;i<=N;i++){
        for(int w=0;w<=W;w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(w - weight[i-1] >= 0)
                K[i][w] = MAX(K[i-1][w],value[i-1]+K[i-1][w-weight[i-1]]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++)
            cout<<K[i][j]<<" ";
        cout<<endl;
    }
    return K[N][W];
}

int main(){
    int N,W;
    cin>>N;
    vector<int>value(N),weight(N);
    for(int i=0;i<N;i++)
        cin>>value[i];
    for(int i=0;i<N;i++)
        cin>>weight[i];
    cin>>W;
    cout<<Knapsack(value,weight,N,W)<<endl;
    return 0;
}