//Program to find the largest square in a 2D matrix with sides comprising of only 1s.

#include <iostream>
#include <vector>

using namespace std;

//Struct used to find the number of 1s above and to the left of the position
struct dim{
    int r,c;
};

inline int MAX(int x,int y){
    return x>y?x:y;
}

inline int MIN(int x,int y){
    return x<y?x:y;
}

int squareOnesSideArea(const vector< vector<int> >&arr,int m,int n){
    //Used to store the number of ones above and to the left of each position
    vector< vector<dim> >len(m,vector<dim>(n));
    //Calculates the length of a square for each position
    int square_len = 0;
    //Calculates max length, returns the square of this for area
    int max_square_len = 0;
    //Setting initial value of (0,0)
    len[0][0].r = arr[0][0]?1:0;
    len[0][0].c = arr[0][0]?1:0;
    //Set the values for the first row
    for(int i=1;i<m;i++){
        len[i][0].r = arr[i][0]?len[i-1][0].r+1:0;
        len[i][0].c = arr[i][0]?1:0;
    }
    //Set the values for the first column
    for(int i=1;i<n;i++){
        len[0][i].r = arr[0][i]?1:0;
        len[0][i].c = arr[0][i]?len[0][i-1].c+1:0;
    }
    //Set every other value
    for(int i=1;i<m;i++){
        for(int j=1;j<m;j++){
            //Increment r with the above value if arr[i][j] is 1 
            len[i][j].r = arr[i][j]?len[i-1][j].r+1:0;
            //Incrememnt c with the left hand value if arr[i][j] is 1 
            len[i][j].c = arr[i][j]?len[i][j-1].c+1:0;
        }
    }
    //Starting from the bottom right
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            //largest square possible can be found by calculating the minimum value of r,c
            square_len = MIN(len[i][j].r,len[i][j].c);
            //if the largest square for this position is less than the max, ignore
            if(square_len<max_square_len)
                continue;
            //Iterate all the square values from square_len-1 to 0
            for(int k=square_len-1;k>=0;k--){
                //Check for out of bounds
                if(i-k>=0 && j-k>=0){
                    //if the left r value and above c value are greater than k+1, check for max
                    if(len[i][j-k].r >= k+1 && len[i-k][j].c >= k+1){
                        max_square_len = MAX(max_square_len,k+1);
                        break;
                    }
                }
            }
        }
    }
    //return area
    return max_square_len*max_square_len;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector< vector<int> >arr(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    cout<<squareOnesSideArea(arr,m,n)<<endl;
    return 0;
}

/*
INPUT
5 5
0 0 0 0 1
1 0 1 1 1
1 0 1 0 1
1 1 1 1 1
0 0 1 1 1
OUTPUT 
9
*/