#include <cstdio>
#include <vector>
#include <algorithm>
const int MAX = 10005;
using namespace std;
int n, m;
struct Edges{
	int a;
	int b;
	int cost;
};

vector <Edges> List;
int Parent[MAX];
int result;

int Find(int x){
	if(x == Parent[x]) return x;
	else{
		Parent[x] = Find(Parent[x]);
		return Parent[x];
	}
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return true;
	else{
		Parent[b] = a;
		return false;
	}
}

bool compare(const Edges& s, const Edges& t){
	if(s.cost < t.cost) return true;
	else if(s.cost == t.cost){
		if(s.a < t.a) return true;
		else if(s.a == t.a){
			if(s.b < t.b) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
Edges make_edges(int a, int b, int c){
	Edges temp;
	temp.a = a;
	temp.b = b;
	temp.cost = c;
	return temp;
}
int main(){
	scanf("%d %d",&n, &m);

	for(int i=1;i<=n;i++) Parent[i] = i;

	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d %d %d",&a, &b, &c);
		List.push_back(make_edges(a, b, c));
	}
	// sort with cost
	sort(List.begin(), List.end(), compare);
	for(int i=0;i<m;i++){
		if(Union(List[i].a, List[i].b) == false)
			result += List[i].cost;
	}
	printf("%d\n",result);
	return 0;
}

