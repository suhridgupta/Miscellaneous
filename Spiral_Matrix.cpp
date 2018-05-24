#include <iostream>
#include <vector>
using namespace std;

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
        int n = 4;
	    int arr[4][4];
        bool visited[6][6];
	    for(int a=0;a<4;a++){
	        for(int b=0;b<4;b++){
	            cin>>arr[a][b];
                visited[a+1][b+1] = false;
	        }
        }
        for(int a=0;a<6;a++){
            visited[a][0] = true;
            visited[0][a] = true;
            visited[a][5] = true;
            visited[5][a] = true;
        }
        int count = 0,i = 0,j = 0,traverse = RIGHT;
        while(count < 16){
            cout<<arr[i][j]<<' ';
            visited[i+1][j+1] = true;
            if(traverse == RIGHT && visited[i+1][j+2])
                traverse = DOWN;
            else if(traverse == DOWN && visited[i+2][j+1])
                traverse = LEFT;
            else if(traverse == LEFT && visited[i+1][j])
                traverse = UP;
            else if(traverse == UP && visited[i][j+1])
                traverse = RIGHT;
            switch(traverse){
                case LEFT:j--;
                break;
                case RIGHT:j++;
                break;
                case UP:i--;
                break;
                case DOWN:i++;
            }
            count++;
        }
        cout<<endl;
	}
	return 0;
}