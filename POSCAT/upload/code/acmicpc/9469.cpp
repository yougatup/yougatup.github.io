#include <cstdio>

using namespace std;

int main()
{
	int p,n;
	double d,a,b,f;

	scanf("%d",&p);
	while(p--)
	{
		scanf("%d %lf %lf %lf %lf",&n,&d,&a,&b,&f);
		printf("%d %.2lf\n",n,f*d/(a+b));
	}

	return 0;
}
