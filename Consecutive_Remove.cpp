#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    queue<string>arr;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        arr.push(x);
    }
    while(arr.size()!=0){
        string t1 = arr.front();
        arr.pop();
        string t2 = arr.front();
        if(t1 != t2){
            cout<<t1<<'\t';
        }
        else
            arr.pop();
    }
    cout<<endl;
    return 0;
}