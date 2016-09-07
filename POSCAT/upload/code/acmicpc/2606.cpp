#include <iostream>

using namespace std;

bool map[110][110]={false};
bool check[110]={false};
int n,m,cnt;

void find(int index)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!check[i] && map[index][i])
		{
			cnt++;
			check[i]=true;
			find(i);
		}
	}
}

int main()
{
	int i,a,b;

	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		map[a][b]=true;
		map[b][a]=true;
	}
	cnt=0;
	check[1]=true;
	find(1);

	cout<<cnt<<endl;

	return 0;
}
