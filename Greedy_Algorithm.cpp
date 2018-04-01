#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>

#define INF 9999

using namespace std;

int dist = 0;

struct node{
	int value;
	int adj;
};

void initMatrix(node **A,int V){
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++){
			A[i][j].value = INF;
			A[i][j].adj = 0;
		}
}

void getMatrixValue(node **A){
	int x,y,d;
	cout<<"Enter Edge\n";
	//Enter vertices which have an edge
	cin>>x>>y;
	//Enter distance between vertices
	cout<<"Enter Distance\n";
	cin>>d;
	A[x][y].value = d;
	A[x][y].adj = 1;
	A[y][x].value = d;
	A[y][x].adj = 1;
}

vector<float> getHeuristics(vector<float>heuristic, int V){
	cout<<"Enter Heuristics For Each Node\n";
	//Enter shortest distance from node to goal node
	for(int i=0;i<V;i++)
		cin>>heuristic[i];
	return heuristic;
}

void printStack(stack<int>sub){
	cout<<"Path: \n";
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

int inVisited(stack<int>visited,int value){
	stack<int>temp = visited;
	while(!temp.empty()){
		if(value == temp.top())
			return 1;
		temp.pop();
	}
	return 0;
}

int minDist(node **A,vector<float>heuristic,int row,int col,stack<int>visited){
	int pos = -1;
	float min = INF;
	for(int i=0;i<col;i++){
		if(heuristic[i]<min && !inVisited(visited,i) && A[row][i].adj){
			min = heuristic[i];
			pos = i;
		}
	}
	return pos;
}

int bestFirstSearch(node **A,vector<float>heuristic,int V,stack<int> visited, int k,int goal){
	if(k == goal){
		printStack(visited);
		return 1;
	}
	int next_state = minDist(A,heuristic,k,V,visited);
	if(next_state != -1){
		dist += A[k][next_state].value;
		visited.push(next_state);
		if(bestFirstSearch(A,heuristic,V,visited,next_state,goal))
			return 1;
	}
	return 0;
}

int main(){
	int V,E,start,goal;
	cout<<"Enter Number of Vertices\n";
	cin>>V;
	stack<int>visited;
	node **A = (node**)malloc(sizeof(node*)*V*V);
	for(int i=0;i<V;i++){
		A[i] = (node*)malloc(sizeof(node)*V);
	}
	vector<float>heuristic(V);
	initMatrix(A,V);
	cout<<"Enter Number of Edges\n";
	cin>>E;
	for(int i=0;i<E;i++)
		getMatrixValue(A);
	heuristic = getHeuristics(heuristic,V);
	cout<<"Enter Start State\n";
	cin>>start;
	cout<<"Enter Goal State\n";
	cin>>goal;
	visited.push(start);
	int result = bestFirstSearch(A,heuristic,V,visited,start,goal);
	if(result)
		cout<<"Best Distance: "<<dist<<endl;
	else
		cout<<"Goal State Not Reachable\n";
	return 0;
}

/*
8
9
0 1
3
0 4
4
1 2
4
1 4
5
2 3
4
2 5
5 
4 5
2
5 6
4
6 7
3
11
10.4
6.7
4
8.9
6.9
3
0
*/