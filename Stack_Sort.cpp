//Program to sort stack using only push() pop() and peek()

#include <iostream>
#include <stack>

using namespace std;

stack<int>s;

void display(){
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    cout<<endl;
}

void sort(){
    int flag = 0;
    int x = s.top();
    s.pop();
    //Recursively move to the second last element
    if(s.empty()){
        s.push(x);
        return;
    }
    sort();
    //compare and swap
    if(x>s.top()){
        int y = s.top();
        s.pop();
        s.push(x);
        s.push(y);
        flag = 1;
    }
    //if not swapped, place the value back as is
    if(!flag)
        s.push(x);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    //called n times
    for(int i=0;i<n;i++){
        sort();
    }
    display();
    return 0;
}