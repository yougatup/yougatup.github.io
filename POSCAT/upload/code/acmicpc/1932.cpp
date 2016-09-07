#include <cstdio>

using namespace std;

int main()
{
	int n,i,j;
	int tri[500][500];
	int sum[500][500];
	int maxi=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&tri[i][j]);
	sum[0][0]=tri[0][0];
	for(i=1;i<n;i++)
	{
		sum[i][0]=tri[i][0]+sum[i-1][0];
		sum[i][i]=tri[i][i]+sum[i-1][i-1];
	}

	for(i=1;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(sum[i-1][j]>sum[i-1][j-1])
				sum[i][j]=tri[i][j]+sum[i-1][j];
			else
				sum[i][j]=tri[i][j]+sum[i-1][j-1];
		}
	}
	for(i=0;i<n;i++)
		if(maxi<sum[n-1][i])
			maxi=sum[n-1][i];
	printf("%d\n",maxi);
	return 0;
}
