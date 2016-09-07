#include <cstdio>

using namespace std;

int main()
{
	int t,i,s,n,q,p,sum;

	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%d %d",&s,&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&q,&p);
			sum+=q*p;
		}
		printf("%d\n",s+sum);
	}

	return 0;
}
