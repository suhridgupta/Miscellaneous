//Program to find the maximum rectangular area under a histogram

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

inline int MAX(int x,int y){
    return x>y?x:y;
}

int histogramArea(const vector<int>&hist){
    int max_area = 0;
    int area = 0;
    int tp; //stores minimum value to compute area
    stack<int>s; //Stores position of histogram points greater than tp;
    int n = hist.size();
    int i=0;
    while(i<n){
        if(s.empty() || hist[i]>hist[s.top()]){
            s.push(i++);
        }
        else{
            tp = s.top();
            s.pop();
            area = hist[tp] * (s.empty()?i:i-s.top()-1);
            max_area = MAX(max_area,area);
        }
    }
    while(!s.empty()){
        tp = s.top();
        s.pop();
        area = hist[tp] * (s.empty()?i:i-s.top()-1);
        max_area = MAX(max_area,area);
    }
    return max_area;
}

int main(){
    int n;
    cin>>n;
    vector<int>hist(n);
    for(vector<int>::iterator i=hist.begin();i!=hist.end();i++)
        cin>>*i;
    cout<<histogramArea(hist)<<endl;
    return 0;
}