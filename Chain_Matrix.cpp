#include <iostream>
#include <vector>

#define INF 9999

using namespace std;

int Chain_Cost(const vector<int>&p,int N){
    vector< vector<int> >M(N, vector<int>(N)); //N*N Matrix
    for(int i=1;i<N;i++){
        M[i][i] = 0; //Cost is 0
    }
    for(int l=2;l<N;l++){ // Length of Chain
        for(int i=1;i<N-l+1;i++){ 
            int j = i+l-1; 
            M[i][j] = INF;
            for(int k=i;k<j;k++){ //Partition b/w i and j
                int q = M[i][k] + M[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q<M[i][j])
                    M[i][j] = q;
            }
        }
    }
    return M[1][N-1]; //Value for the entire matrix multiplication cost
}

int main(){
    int N;
    cin>>N;
    vector<int>p(N);
    for(int i=0;i<N;i++)
        cin>>p[i];
    cout<<Chain_Cost(p,N);
}