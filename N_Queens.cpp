#include <iostream>
#include <stdlib.h>

using namespace std;

void displayBoard(int **A,int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<A[i][j]<<' ';
		cout<<endl;
	}
}

int checkValidity(int **A, int N, int row, int col){
	int i,j;
	for (i = 0; i < col; i++)
        if (A[row][i])
            return 0;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (A[i][j])
            return 0;
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (A[i][j])
            return 0;
    return 1;
}

int nQueens(int **A,int N,int j){
	if(j>=N){
		return 1;
	}
	for(int i=0;i<N;i++){
		if(checkValidity(A,N,i,j)){
			A[i][j] = 1;
			if(nQueens(A,N,j+1))
				return 1;
			A[i][j] = 0;
		}

	}
	return 0;
}

int main(){
	int N;
	cout<<"Enter Board Size\n";
	cin>>N;
	int **A = (int**)malloc(sizeof(int*)*N*N);
	for(int i=0;i<N;i++)
		A[i] = (int*)malloc(sizeof(int*)*N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			A[i][j] = 0;
	int result = nQueens(A,N,0);
	displayBoard(A,N);
	return 0;
}