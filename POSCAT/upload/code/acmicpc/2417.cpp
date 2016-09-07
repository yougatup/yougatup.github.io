#include <cstdio>

using namespace std;

int main()
{
	unsigned long long int x,s=0,e,m;
	scanf("%llu",&x);
	e=x;
	while(s<=e)
	{
		m=(s+e)/2;
		if(m*m>x)
			e=m-1;
		else
			s=m+1;
	}
	printf("%llu\n",m);
	return 0;
}
