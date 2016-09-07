#include <cstdio>

using namespace std;

char map[1000][1001];
int n;

bool bound(int x,int y)
{
	return 0<=x && x<n && 0<=y && y<n;
}

int main()
{
	int i,j,k,l,cur;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",map[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j]!='.')
			{
				printf("*");
				continue;
			}
			cur=0;
			for(k=-1;k<=1;k++)
				for(l=-1;l<=1;l++)
					if(bound(i+k,j+l) && map[i+k][j+l]!='.')
						cur+=map[i+k][j+l]-'0';
			if(cur<10)
				printf("%d",cur);
			else
				printf("M");
		}
		printf("\n");
	}
	return 0;
}
