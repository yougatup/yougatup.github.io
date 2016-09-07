#include <cstdio>

using namespace std;

long long int n,accum=0;

void find(long long int p,long long int index)
{
	if(n<10*p)
		accum+=(n-(p-1))*index;
	else
	{
		accum+=9*p*index;
		find(10*p,index+1);
	}
}

int main()
{
	scanf("%lld",&n);
	find(1,1);
	printf("%lld\n",accum);
	return 0;
}
