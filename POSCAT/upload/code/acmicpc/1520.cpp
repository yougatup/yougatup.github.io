#include <cstdio>

using namespace std;

int map[500][500];
int slop[500][500];
int m,n;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

bool bound(int x,int y)
{
	return 0<=x && x<m && 0<=y && y<n;
}

int find(int x, int y)
{
	int i,cur=0,xx,yy;
	if(x==0 && y==0)
		return 1;
	if(slop[x][y]!=-1)
		return slop[x][y];

	for(i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(bound(xx,yy) && map[x][y]<map[xx][yy])
			cur+=find(xx,yy);
	}
	slop[x][y]=cur;
	return cur;
}
int main()
{
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&map[i][j]);
			slop[i][j]=-1;
		}

	printf("%d\n",find(m-1,n-1));

	return 0;
}
