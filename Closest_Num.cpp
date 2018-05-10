#include <iostream>

using namespace std;

int Closest_Num(int m,int n){
    int q = n/m;
    int ans1 = q*m,ans2;
    if(n%m == 0 && n!=0)
        return ans1;
    if(n*m<0)  //One Number is -ve
        ans2 = m*(q-1);
    else
        ans2 = m*(q+1);
    return abs(n - ans1)<abs(n - ans2)?ans1:ans2;
}

int main(){
    int T,m,n;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m;
        cout<<Closest_Num(m,n)<<endl;
    }
    return 0;
}