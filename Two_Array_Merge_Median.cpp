//Program to find the median of the combination of two sorted arrays

#include <iostream>
#include <vector>

#define INF 9999

using namespace std;

inline double avg(const int a,const int b){
    return (double)(a+b)/2;
}

inline double min(const int a,const int b){
    return a<b?a:b;
}

inline double max(const int a,const int b){
    return a>b?a:b;
}

double findMedian(const vector<int>&a,const vector<int>&b){
    int m = a.size(),n = b.size();
    
    if(m>n)
        return findMedian(b,a); //To ensure we calculate the partition using the smaller array
    
    int start = 0,end = m;    
    int partitionX,partitionY; //Used to partition the two arrays
    
    while(start<=end){
        partitionX = (start+end)/2; //partition X between start and end
        partitionY = (m+n+1)/2-partitionX; //partition y in such a way, so that both partitions have equal number of elements (or one greater on the left side) for their combined lefts and rights
        
        int left_a = partitionX>0?a[partitionX-1]:-INF; //choose the last element of the left partition, otherwise -infinity
        int right_a = partitionX<m?a[partitionX]:INF; //choose the first element of the right partition, otherwise +infinity
        int left_b = partitionY>0?b[partitionY-1]:-INF;
        int right_b = partitionY<n?b[partitionY]:INF;
        
        if(left_a<=right_b && left_b<=right_a){ //condition met, if even number, avg of max of left and min of right, otherwise simply max of left
            return (m+n)%2==0?avg(max(left_a,left_b),min(right_a,right_b)):max(left_a,left_b);
        }
        else if(left_a>right_b){ //left is overloaded, so shift the partition to the left
            end = partitionX-1;
        }
        else{ //right is overloaded so shift the partition to the right
            start = partitionX+1;
        }
    }
    return -1; //probably never called???
}

int main(){
    int m,n;
    cin>>m;
    vector<int>a(m);
    for(int i=0;i<m;i++)
        cin>>a[i];
    cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<findMedian(a,b)<<endl;
    return 0;
}