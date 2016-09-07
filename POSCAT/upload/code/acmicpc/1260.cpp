#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1005;
int Matrix[MAX][MAX];
bool Check[MAX];
int n, m, start;
void DFS(int x){ // x부터 시작해서 DFS 하는애
	Check[x] = true;
	printf("%d ",x);
	for(int i=1;i<=n;i++){
		if(Matrix[x][i] == 1 && Check[i] == false){
			DFS(i);
		}
	}
}
void BFS(int x){ // x부터 시작해서 BFS
	queue <int> Queue;
	Queue.push(x);
	Check[x] = true;

	while(!Queue.empty()){
		int Node = Queue.front();
		Queue.pop();

		printf("%d ",Node);

		for(int i=1;i<=n;i++){
			if(Matrix[Node][i] == 1 && Check[i] == false){
				Check[i] = true;
				Queue.push(i);
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n, &m, &start);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d %d",&a, &b);
		Matrix[a][b] = 1;
		Matrix[b][a] = 1;
	}

	DFS(start);
	printf("\n");

	for(int i=1;i<=n;i++) Check[i] = false;

	BFS(start);
	printf("\n");

	return 0;
}

