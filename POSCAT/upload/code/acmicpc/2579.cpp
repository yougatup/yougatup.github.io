#include <cstdio>
#include <algorithm>

using namespace std;

int stair[300];
int d[300][2];

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&stair[i]);

	if(n==1)
	{
		printf("%d\n",stair[0]);
		return 0;
	}
	if(n==2)
	{
		printf("%d\n",stair[0]+stair[1]);
		return 0;
	}

	d[0][0]=0;
	d[0][1]=stair[0];
	d[1][0]=stair[1];
	d[1][1]=stair[0]+stair[1];

	for(i=2;i<n;i++)
	{
		d[i][0]=stair[i]+max(d[i-2][0],d[i-2][1]);
		d[i][1]=stair[i]+d[i-1][0];
	}

	printf("%d\n",max(d[n-1][0],d[n-1][1]));
	return 0;
}
