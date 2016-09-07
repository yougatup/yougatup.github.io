#include <cstdio>

using namespace std;

int main()
{
	int a,b,n;
	int i;

	scanf("%d %d %d",&a,&b,&n);
	for(i=0;i<n;i++)
	{
		a%=b;
		a*=10;
	}
	printf("%d\n",a/b);
	return 0;
}
