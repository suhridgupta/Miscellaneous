#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    string s;
	    cin>>s;
	    sort(s.begin(),s.end()); //To ensure lexicographic order
	    do{
	        cout<<s<<' ';
	    }while(next_permutation(s.begin(),s.end()));
	    cout<<endl;
	}
	return 0;
}