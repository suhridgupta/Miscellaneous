//Program to compute the minimum cost to traverse from [0,0] to [m,n] using left,down,right diagonal movement only
#include <iostream>
#include <vector>

using namespace std;

void minMove(const vector< vector<int> > &cost,int *i,int *j){
    if(*i+1 == cost.size() && *j+1 != cost[0].size()){
        *j = *j+1;
    }
    else if(*i+1 != cost.size() && *j+1 == cost[0].size()){
        *i = *i+1;
    }
    else if(cost[*i][*j+1]<cost[*i+1][*j] && cost[*i][*j+1]<cost[*i+1][*j+1]){
        *j = *j+1;
    }
    else if(cost[*i+1][*j]<cost[*i][*j+1] && cost[*i+1][*j]<cost[*i+1][*j+1]){
        *i = *i+1;
    }
    else{
        *i = *i+1;
        *j = *j+1;
    }
}

int minCost(const vector< vector<int> > &cost){
    int m = cost.size(),n = cost[0].size(),i=0,j=0,x=0,y=0;
    int path_cost = cost[i][j];
    while(i != m - 1 || j != n - 1){
        minMove(cost,&x,&y);
        path_cost += cost[x][y];
        i = x;
        j = y;
    }
    return path_cost;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector< vector<int> >cost(m,vector<int>(n));
    for(vector< vector<int> >::iterator i=cost.begin();i!=cost.end();i++)
        for(vector<int>::iterator j=i->begin();j!=i->end();j++)
            cin>>*j;
    cout<<minCost(cost)<<endl;
    return 0;
}