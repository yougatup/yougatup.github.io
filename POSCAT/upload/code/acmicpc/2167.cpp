#include <cstdio>

using namespace std;

int sum[330][330]={0};
int arr[330][330];

int main()
{
	int n,m,k;
	int i,j,x,y,l;

	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&arr[i][j]);

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+arr[i][j];
	
	scanf("%d",&k);
	for(l=0;l<k;l++)
	{
		scanf("%d %d %d %d",&i,&j,&x,&y);
		printf("%d\n",sum[x][y]-sum[x][j-1]-sum[i-1][y]+sum[i-1][j-1]);
	}

	return 0;
}
