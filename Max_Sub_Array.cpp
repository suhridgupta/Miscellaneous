#include <iostream>
#include <vector>

#define INF 9999
using namespace std;

int maxCross(vector<int>A,int low,int mid,int high){
	int lsum = -INF;
	int sum = 0;
	for(int i=mid;i>=low;i--){
		sum+=A[i];
		if(sum>lsum){
			lsum = sum;
		}
	}
	int rsum = -INF;
	sum = 0;
	for(int i=mid+1;i<=high;i++){
		sum+=A[i];
		if(sum>rsum){
			rsum = sum;
		}
	}
	return (lsum+rsum);
}

int maxSubArray(vector<int>A,int low,int high){
	if(low == high)
		return A[low];
	int mid = (low+high)/2;
	int lsum = maxSubArray(A,low,mid);
	int rsum = maxSubArray(A,mid+1,high);
	int csum = maxCross(A,low,mid,high);
	if(lsum>=rsum && lsum>=csum)
		return lsum;
	else if(rsum>=lsum && rsum>=csum)
		return rsum;
	return csum;
}

int main(){
	int n;
	cout<<"Enter Size\n";
	cin>>n;
	vector<int>A(n);
	cout<<"Enter Elements\n";
	for(vector<int>::iterator i = A.begin();i!=A.end();i++){
		cin>>*i;
	}
	int sum = maxSubArray(A,0,n-1);
	cout<<sum<<endl;
	return 0;
}
