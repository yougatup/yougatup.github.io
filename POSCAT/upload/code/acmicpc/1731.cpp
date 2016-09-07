#include <cstdio>

using namespace std;

int main()
{
	int n,a,b,c,i;

	scanf("%d %d %d %d",&n,&a,&b,&c);

	if(a+c==b*2)
	{
		for(i=3;i<=n;i++)
			c+=b-a;
	}
	else
	{
		for(i=3;i<=n;i++)
			c*=b/a;
	}

	printf("%d\n",c);

	return 0;
}
