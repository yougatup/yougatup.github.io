#include <cstdio>

using namespace std;

int main()
{
	int n,m,i,mini=10001,sum=0;

	scanf("%d %d",&n,&m);
	for(i=1;i*i<=m;i++)
	{
		if(i*i>=n)
		{
			sum+=i*i;
			if(mini>i*i)
				mini=i*i;
		}
	}

	if(sum!=0)
		printf("%d\n%d\n",sum,mini);
	else
		printf("-1\n");

	return 0;
}
