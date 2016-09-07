#include <iostream>

using namespace std;

int m,n,k;
int t;
bool map[60][60];

bool isBound(int x,int y)
{
	return 0<=x && x<n && 0<=y && y<m;
}

void find(int x,int y)
{
	int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	int i;
	for(i=0;i<4;i++)
		if(isBound(x+dir[i][0],y+dir[i][1]) && map[x+dir[i][0]][y+dir[i][1]])
		{
			map[x+dir[i][0]][y+dir[i][1]]=false;
			find(x+dir[i][0],y+dir[i][1]);
		}
}

int main()
{
	int i,j,a,b,cnt;
	cin>>t;
	while(t-->0)
	{
		cin>>m>>n>>k;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				map[i][j]=false;
		cnt=0;
		for(i=0;i<k;i++)
		{
			cin>>a>>b;
			map[b][a]=true;
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(map[i][j])
				{
					map[i][j]=false;
					cnt++;
					find(i,j);
				}
		cout<<cnt<<endl;
	}

	return 0;
}
