#include <cstdio>

using namespace std;

int c[10001]={0};

int main()
{
	int n,k,i,j,in;

	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		if(in<=k)
			c[in]=1;
		for(j=1;in+j<=k;j++)
			if((c[in+j]==0 || c[in+j]>c[j]+1)&&c[j]!=0)
				c[in+j]=c[j]+1;
	}
	if(c[k]==0)
		c[k]=-1;
	printf("%d\n",c[k]);
	return 0;
}
