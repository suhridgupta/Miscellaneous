//Program to find the shortest path between all pairs of vertices
#include <iostream>
#include <vector>

#define MIN(X,Y) (X<Y?X:Y)

using namespace std;

void printMat(vector< vector<int> >&dist){
    for(vector< vector<int> >::iterator i=dist.begin();i!=dist.end();i++){
        for(vector<int>::iterator j=i->begin();j!=i->end();j++)
            cout<<*j<<'\t';
        cout<<endl;
    }
}

void floydWarshall(const vector< vector<int> >&mat){
    int n = mat.size();
    vector< vector<int> >dist(n,vector<int>(n));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j] = mat[i][j];

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = MIN(dist[i][j],dist[i][k]+dist[k][j]);
    
    printMat(dist);
}

int main(){
    int n;
    cin>>n;
    vector< vector<int> >mat(n,vector<int>(n));
    for(vector< vector<int> >::iterator i=mat.begin();i!=mat.end();i++)
        for(vector<int>::iterator j=i->begin();j!=i->end();j++)
            cin>>*j;
    floydWarshall(mat);
    return 0;
}