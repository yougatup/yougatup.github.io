#include <cstdio>

using namespace std;

int main()
{
	int t;
	long long int n,j;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n<=2)
		{
			printf("2\n");
			continue;
		}
		for(n+=(n%2==0);;n+=2)
		{
			for(j=3;j*j<=n;j+=2)
				if(n%j==0)
					break;
			if(j*j>n)
				break;
		}
		printf("%lld\n",n);
	}
	return 0;
}
