#include <cstdio>

using namespace std;

int main()
{
	long long int fibo[91]={0,1,1,2};
	int i;
	for(i=4;i<=90;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
	scanf("%d",&i);
	printf("%lld\n",fibo[i]);

	return 0;
}
