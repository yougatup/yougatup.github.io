#include <cstdio>
#include <algorithm>

using namespace std;

int d[10000][3];

int main()
{
	int n,i,in;
	scanf("%d",&n);
	scanf("%d",&d[0][1]);
	d[0][0]=d[0][2]=0;
	for(i=1;i<n;i++)
	{
		scanf("%d",&in);
		d[i][0]=max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
		d[i][1]=in+d[i-1][0];
		d[i][2]=in+d[i-1][1];
	}
	printf("%d\n",max(d[n-1][0],max(d[n-1][1],d[n-1][2])));
	return 0;
}
