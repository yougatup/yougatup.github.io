#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

string map[100];
bool check[100][100];
int n,m;
queue<pair<pair<int,int>,int> > qu;

bool bound(int x,int y)
{
	return 0<=x && x<n && 0<=y && y<m;
}

void bfs()
{
	pair<pair<int,int>,int> p;
	pair<int,int> pf;
	int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int i,len;
	int x,y;

	p.first.first=p.first.second=0;
	p.second=len=1;
	qu.push(p);
	while(!qu.empty())
	{
		p=qu.front();
		pf=p.first;
		len=p.second;
		qu.pop();
		if(pf.first==n-1 && pf.second==m-1)
		{
			cout<<len<<endl;
			return;
		}
		//cout<<pf.first<<" "<<pf.second<<endl;
		for(i=0;i<4;i++)
		{
			x=pf.first+dir[i][0];
			y=pf.second+dir[i][1];
			if(bound(x,y) && map[x][y]=='1' && !check[x][y])
			{
				check[x][y]=true;
				qu.push(make_pair(make_pair(x,y),len+1));
			}
		}
	}
}

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>map[i];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			check[i][j]=false;
	bfs();
	return 0;
}
