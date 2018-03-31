#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printSubset(stack<int>sub){
	stack<int>temp;
	while(!sub.empty()){
		temp.push(sub.top());
		sub.pop();
	}
	while(!temp.empty()){
		cout<<temp.top()<<'\t';
		temp.pop();
	}
	cout<<endl;	
}

int subsetSum(vector<int>arr,stack<int>sub,vector<int>visited,int k,int sum){
	if(k == sum){
		printSubset(sub);
		return 1;
	}
	for(int i=0;i<arr.size();i++){
		if((sum+arr[i])<=k && !visited[i]){
			visited[i] = 1;
			sub.push(arr[i]);
			sum+=arr[i];
			if(subsetSum(arr,sub,visited,k,sum))
				return 1;
			visited[i] = 0;
			sum -= arr[i];
			sub.pop();
		}
	}
	return 0;
}

int main(){
	int n,k;
	cout<<"Enter Size\n";
	cin>>n;
	vector<int>arr(n);
	vector<int>visited(n);
	stack<int>sub;
	cout<<"Enter Array Values\n";
	for(int i=0;i<n;i++){
		visited[i] = 0;
		cin>>arr[i];
	}
	cout<<"Enter Sum\n";
	cin>>k;
	int res = subsetSum(arr,sub,visited,k,0);
	if(!res)
		cout<<"No Subset Exists\n";
	return 0;
}