#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1005;
const int inf = 1000000000;
int n, m;
int start, end;
vector <int> List[MAX];
vector <int> Cost[MAX];
int S[MAX];
int Table[MAX][MAX];
bool Check[MAX];
int Bellman(int st, int ed){
	for(int i=1;i<=n;i++) S[i] = inf;
	S[st] = 0;

	for(int i=0;i<n-1;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<List[j].size();k++){
				int Node2 = List[j][k];
				int Cost2 = Cost[j][k];

				S[Node2] = min(Cost2 + S[j], S[Node2]);
			}
		}
	}
	return S[ed];
}
int Floyd(int st, int ed){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				Table[i][j] = min(Table[i][j], Table[i][k] + Table[k][j]);
			}
		}
	}
	return Table[st][ed];
}
int Dijkstra(int st, int ed){
	for(int i=1;i<=n;i++) S[i] = inf;
	S[st] = 0;

	for(int i=0;i<n;i++){
		int min_value = inf;
		int min_inx = -1;
		for(int j=1;j<=n;j++){
			if(Check[j] == false && min_value > S[j]){
				min_value = S[j];
				min_inx = j;
			}
		}

		// min_value
		Check[min_inx] = true;

		// Move !

		for(int j=0;j<List[min_inx].size();j++){
			int Node2 = List[min_inx][j];
			int Cost2 = Cost[min_inx][j];
			// min_inx -- (Cost2) -- Node2

			S[Node2] = min(S[Node2], S[min_inx] + Cost2);
		}
	}
	return S[ed];
}
int main(){
	scanf("%d %d",&n, &m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) Table[i][j] = inf;
	}
	for(int i=1;i<=n;i++) Table[i][i] = 0;

	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d %d %d",&a, &b, &c);
		List[a].push_back(b);
		Cost[a].push_back(c);
		Table[a][b] = c;
	}
	scanf("%d %d",&start, &end);
	printf("%d\n",Dijkstra(start, end));
	return 0;
}
