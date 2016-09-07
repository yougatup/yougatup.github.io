#include <cstdio>

using namespace std;

int main()
{
	int q,d,n;
	int t,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&c);
		q=c/25;
		c-=q*25;
		d=c/10;
		c-=d*10;
		n=c/5;
		c-=n*5;
		printf("%d %d %d %d\n",q,d,n,c);
	}
}
