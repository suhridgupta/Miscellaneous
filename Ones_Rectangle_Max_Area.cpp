//Program to find the maximum area covered by 1s in a matrix

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

inline int MAX(int x, int y){
    return x>y?x:y;
}

int maxHistogramArea(const vector<int>&hist){
    int n = hist.size();
    int max_area = 0;
    int area = 0;
    int tp = 0;
    stack<int>s;
    int i = 0;
    while(i<n){
        if(s.empty() || hist[i]>hist[s.top()]){
            s.push(i++);
        }
        else{
            tp = s.top();
            s.pop();
            area = hist[tp]*(s.empty()?i:i-s.top()-1);
            max_area = MAX(max_area,area);
        }
    }
    while(!s.empty()){
        tp = s.top();
        s.pop();
        area = hist[tp]*(s.empty()?i:i-s.top()-1);
        max_area = MAX(max_area,area);
    }
    return max_area;
}

int maxArea(const vector< vector<int> >&arr, int m, int n){
    vector<int>row(n,0); //Used to create histograms for each row
    int max_area = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //if value is zero, histogram for that value is destroyed, otherwise height incremented
            if(arr[i][j] == 0)
                row[j] = 0;
            else
                row[j]++;
        }
        max_area = MAX(max_area,maxHistogramArea(row));
    }
    return max_area;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector< vector<int> >arr(m,vector<int>(n));
    for(vector<vector<int> >::iterator i=arr.begin();i!=arr.end();i++)
        for(vector<int>::iterator j=i->begin();j!=i->end();j++)
            cin>>*j;
    cout<<maxArea(arr,m,n)<<endl;
    return 0;
}