#include <cstdio>

using namespace std;

int main()
{
	int t,n,i;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		i=0;
		while(n!=0)
		{
			if(n%2==1)
				printf("%d ",i);
			n/=2;
			i++;
		}
		printf("\n");
	}
	return 0;
}
