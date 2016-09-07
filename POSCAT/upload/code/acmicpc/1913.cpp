#include <cstdio>

using namespace std;

int d[1000][1000];

int main()
{
	int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int n,q,i,j;
	int x,y;
	int resx,resy;
	int cnt;
	int w;

	scanf("%d %d",&n,&q);
	
	x=(n-1)/2;
	y=(n-1)/2;
	d[x--][y]=1;
	d[x][y]=2;

	if(q==1)
	{
		resx=x+1;
		resy=y;
	}
	if(q==2)
	{
		resx=x;
		resy=y;
	}

	cnt=3;
	w=1;
	while(cnt<=n*n)
	{
		for(i=0;i<4;i++)
		{
			if(i%2==1)
				w++;
			for(j=0;j<w;j++)
			{
				x+=dir[i][0];
				y+=dir[i][1];
				if(cnt==q)
				{
					resx=x;
					resy=y;
				}
				if(cnt<=n*n)
					d[x][y]=cnt++;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
	printf("%d %d\n",resx+1,resy+1);

	return 0;
}
