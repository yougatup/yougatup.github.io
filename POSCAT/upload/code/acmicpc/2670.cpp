#include <cstdio>

using namespace std;

int main()
{
	double maxi,cur,in;
	int n;
	scanf("%d",&n);
	scanf("%lf",&cur);
	maxi=cur;
	while(--n)
	{
		scanf("%lf",&in);
		if(cur<1)
			cur=in;
		else
			cur*=in;
		if(maxi<cur)
			maxi=cur;
	}
	printf("%.3lf\n",maxi);

	return 0;
}
