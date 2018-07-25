//Program to solve an equation with operations +-*/
#include <bits/stdc++.h>

#define ADD -1
#define SUB -2
#define MUL -3
#define DIV -4

using namespace std;

int calcResult(string a){
    int n = a.size(),i=0;
    vector<int>arr; //stores the equation in the form of integers
    string num = ""; //to store each number in the string
    while(i<n){
        //if we encounter an operator, store the number, clear num, and store operator
        if(a[i]<'0' || a[i]>'9'){ 
            int x = 0;
            stringstream s(num); //string stream to store the num
            s>>x; //push number into a temporary int
            arr.push_back(x);
            num = "";
            switch(a[i]){
                case '+':arr.push_back(ADD);i++;break;
                case '-':arr.push_back(SUB);i++;break;
                case '*':arr.push_back(MUL);i++;break;
                case '/':arr.push_back(DIV);i++;break;
            }
        }
        else //otherwise just push the character into the number string
            num+=a[i++];
    }
    //push the last number, because it does not satisfy the loop condition
    int x = 0;
    stringstream s(num);
    s>>x;
    arr.push_back(x);

    int flag=1;
    int len = arr.size();
    //Loop over the array till all mul and div operations are completed, shortening the len by 2 each time
    while(flag){
        flag=0;
        i=1;
        while(i<len){
            if(arr[i] == MUL || arr[i] == DIV){
                flag = 1;
                if(arr[i] == MUL)
                    arr[i-1] *= arr[i+1];
                else
                    arr[i-1] /= arr[i+1];
                for(int j=i;j<len-2;j++){
                    arr[j] = arr[j+2];
                }
                len-=2;
            }
            i++;
        }
    }

    flag = 1;
    //now do the same for add and sub
    while(flag){
        flag=0;
        i=1;
        while(i<len){
            if(arr[i] == ADD || arr[i] == SUB){
                flag = 1;
                if(arr[i] == ADD)
                    arr[i-1] += arr[i+1];
                else
                    arr[i-1] -= arr[i+1];
                for(int j=i;j<len-2;j++){
                    arr[j] = arr[j+2];
                }
                len-=2;
            }
        }
    }
    //final result is stored in the first arr element
    return arr[0];
}

int main(){
    string a;
    cin>>a;
    cout<<calcResult(a)<<endl;
}