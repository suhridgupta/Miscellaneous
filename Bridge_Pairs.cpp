#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct bridge{
    int x,y;
};

bool sortByX(const bridge &a,const bridge &b){
    return (a.y==b.y)?(a.x<b.x):(a.y<b.y); //If y values are equal, sort using x values
}

int findMax(vector<bridge>&pairs,int val,int len){
    int max = 0,pos = -1;
    for(int i=0;i<len;i++)
        if(pairs[i].x<val && pairs[i].x>max){
            max = pairs[i].x;
            pos = i;
        }
    return pos;
}

int bridgePairs(vector<bridge>&pairs){
    int max = 0;
    vector<int>dist(pairs.size(),1);
    sort(pairs.begin(),pairs.end(),sortByX);
    for(int i=0;i<pairs.size();i++){
        int pos = findMax(pairs,pairs[i].x,i);
        if(pos != -1)
            dist[i] = dist[pos] + 1;
    }
    for(int i=0;i<dist.size();i++)
        if(dist[i]>max)
            max = dist[i];
    return max;
}

int main(){
    int n;
    cin>>n;
    vector<bridge>pairs(n);
    for(vector<bridge>::iterator i=pairs.begin();i!=pairs.end();i++)
        cin>>i->x>>i->y;
    cout<<bridgePairs(pairs)<<endl;
    return 0;
}