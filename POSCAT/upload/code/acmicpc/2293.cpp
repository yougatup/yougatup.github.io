#include <cstdio>

using namespace std;

int c[10001]={1};

int main()
{
	int n,k,i,j,in;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		for(j=0;in+j<=k;j++)
			c[in+j]+=c[j];
	}
	printf("%d\n",c[k]);
	return 0;
}
