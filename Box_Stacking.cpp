//Program to determine tallest tower possible from a given set of boxes
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(X,Y) (X>Y?X:Y)
#define MIN(X,Y) (X<Y?X:Y)

using namespace std;

struct dim{
    int x,y,z;
};

bool comp(const dim &a,const dim &b){
    return ((a.y*a.z)==(b.y*b.z))?(a.x<b.x):(a.y*a.z)>(b.y*b.z);
}

int boxStack(const vector<dim>&boxes){
    int n = boxes.size(),index = 0,max = 0;
    vector<dim>permutation(n*3);
    vector<int>height(n*3);
    for(int i=0;i<n;i++){
        permutation[index].x = boxes[i].x;
        permutation[index].y = MIN(boxes[i].y,boxes[i].z);
        permutation[index++].z = MAX(boxes[i].y,boxes[i].z);

        permutation[index].x = boxes[i].y;
        permutation[index].y = MIN(boxes[i].x,boxes[i].z);
        permutation[index++].z = MAX(boxes[i].x,boxes[i].z);

        permutation[index].x = boxes[i].z;
        permutation[index].y = MIN(boxes[i].x,boxes[i].y);
        permutation[index++].z = MAX(boxes[i].x,boxes[i].y);
    }

    sort(permutation.begin(),permutation.end(),comp);
    
    for(int i=0;i<3*n;i++)
        height[i] = permutation[i].x;

    for(int i=0;i<3*n;i++){
        for(int j=0;j<i;j++){
            if(permutation[i].y<permutation[j].y && permutation[i].z<permutation[j].z && height[i]<height[j]+permutation[i].x)
                height[i] = height[j]+permutation[i].x;
        }
    }
    for(int i=0;i<3*n;i++)
        if(max<height[i])
            max = height[i];
    return max;
}


int main(){
    int n;
    cin>>n;
    vector<dim>boxes(n);
    for(vector<dim>::iterator i=boxes.begin();i!=boxes.end();i++)
        cin>>i->x>>i->y>>i->z;
    cout<<boxStack(boxes)<<endl;
    return 0;
}