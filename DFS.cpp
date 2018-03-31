#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void getEdges(int **A){
	int x,y;
	cin>>x>>y;
	A[x][y] = 1;
}

void printMatrix(int **A, int V){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)
			cout<<A[i][j]<<'\t';
		cout<<endl;
	}
}

void DFS(int **A,int *visited,int i,int V){
	cout<<i<<endl;
	visited[i] = 1;
	for(int j=0;j<V;j++){
		if(!visited[j] && A[i][j])
			DFS(A,visited,j,V);
	}
}

int main(){
	int V;
	int E;
	cout<<"Enter Size\n";
	cin>>V;
	int **A = (int**)malloc(sizeof(int*)*V*V);
	int *visited = (int*)malloc(sizeof(int)*V);
	for(int i=0;i<V;i++)
		A[i] = (int*)malloc(sizeof(int)*V);
	cout<<"Enter Number of Edges\n";
	cin>>E;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)
			A[i][j] = 0;
		visited[i] = 0;
	}
	for(int i=0;i<E;i++)
		getEdges(A);
	DFS(A,visited,0,V);
	return 0;
}