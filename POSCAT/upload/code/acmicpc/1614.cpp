#include <cstdio>

using namespace std;

int main()
{
	long long int a,b;

	scanf("%lld %lld",&a,&b);
	if(a==1 || a==5)
		printf("%lld\n",8*b+(a-1));
	else
	{
		if(b%2==0)
			printf("%lld\n",8*(b/2)+(a-1));
		else
			printf("%lld\n",8*(b/2+1)-(a-1));
	}

	return 0;
}
