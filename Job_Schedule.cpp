//Program To assign non-overlapping jobs to attain max profit

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Start time, end time, and profit of each job;
struct job{
    int start,end,profit;
};

bool comp(const job x, const job y){
    return x.end<y.end;
}

inline int MAX(int x,int y){
    return x>y?x:y;
}

int assignJob(const vector<job>&arr){
    int n = arr.size();
    vector<int>total_profit(n);
    //Initially assign total profit to each job
    for(int i=0;i<n;i++){
        total_profit[i] = arr[i].profit;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j].end <= arr[i].start){ //If jobs dont overlap, add current profit to total
                total_profit[i] = MAX(total_profit[i],total_profit[j]+arr[i].profit);
            }
        }
    }
    //Iterate through array and return max profit
    return *max_element(total_profit.begin(),total_profit.end());
}

int main(){
    int n;
    cin>>n;
    vector<job>arr(n);
    for(vector<job>::iterator i=arr.begin();i!=arr.end();i++){
        cin>>i->start>>i->end>>i->profit;
    }
    //Sort jobs in ascending order of their end times
    sort(arr.begin(),arr.end(),comp);
    cout<<assignJob(arr)<<endl;
    return 0;
}