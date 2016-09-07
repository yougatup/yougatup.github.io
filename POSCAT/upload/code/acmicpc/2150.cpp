#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10005;
vector <int> List[MAX];
vector <int> List2[MAX];
vector <int> result[MAX];
int result_inx = 0;
int Inverted[MAX];
vector <int> Sequence;
bool Check[MAX];
int n, m;
void DFS1(int x){
	Check[x] = true;

	for(int i=0;i<List[x].size();i++){
		int Node2 = List[x][i];
		if(Check[Node2] == false)
			DFS1(Node2);
	}

	Sequence.push_back(x);
}

void getResult(int x){
	Check[x] = true;
	result[result_inx].push_back(x);

	for(int i=0;i<List2[x].size();i++){
		int Node2 = List2[x][i];

		if(Check[Node2] == false){
			Check[Node2] = true;
			getResult(Node2);
		}
	}
}
int main(){
	scanf("%d %d",&n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d %d",&a, &b);
		List[a].push_back(b);
		List2[b].push_back(a);
	}
	// DFS. end time ����

	for(int i=1;i<=n;i++){
		if(Check[i] == false){
			DFS1(i);
		}
	}

	// Sequence ����

	// end time ū����� ���ʴ�� DFS
	reverse(Sequence.begin(), Sequence.end()); // we need #include <algorithm>

	memset(Check, 0, sizeof(Check)); // Check�� 0���� �ʱ�ȭ, #include <string.h>

	for(int i=0;i<Sequence.size();i++){
		int mine = Sequence[i];

		if(Check[mine] == false){
			getResult(mine);
			result_inx++;
		}
	}

	for(int i=0;i<result_inx;i++) sort(result[i].begin(), result[i].end());

	printf("%d\n",result_inx);
	memset(Inverted, -1, sizeof(Inverted));
	for(int i=0;i<result_inx;i++){
		Inverted[result[i][0]] = i;
	}

	for(int i=1;i<=n;i++){
		if(Inverted[i] != -1){
			int inx = Inverted[i];
			for(int j=0;j<result[inx].size();j++) printf("%d ",result[inx][j]);
			printf("-1\n");
		}
	}
	return 0;
}

