#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	double x,y;
	int n,t,alpha;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf",&x,&y);
		y-=x;
		if(y<=3)
		{
			printf("%.0lf\n",y);
			continue;
		}
		n=sqrt(y);
		alpha=y-n*n;
		if(alpha%n==0)
			alpha/=n;
		else
			alpha=alpha/n+1;
		printf("%d\n",2*n-1+alpha);
	}
	return 0;
}
