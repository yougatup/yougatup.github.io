#include <iostream>

using namespace std;

bool tree[110][110]={false};
bool check[110]={false};
int n;

bool dfs(int from,int to, int depth)
{
	if(from==to)
	{
		cout<<depth<<endl;
		return true;
	}

	int i;
	for(i=1;i<=n;i++)
	{
		if(tree[from][i] && !check[i])
		{
			check[i]=true;
			if(dfs(i,to,depth+1))
				return true;
		}
	}
	return false;
}

int main()
{
	int m,x,y,i,j;
	int a,b;

	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			tree[i][j]=false;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		tree[x][y]=true;
		tree[y][x]=true;
	}
	for(i=1;i<=n;i++)
		check[i]=false;

	check[a]=true;
	if(!dfs(a,b,0))
		cout<<-1<<endl;

	return 0;
}
