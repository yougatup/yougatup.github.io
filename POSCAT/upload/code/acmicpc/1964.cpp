#include <cstdio>

using namespace std;

int main()
{
	long long int k;
	scanf("%lld",&k);
	k=3*(k+1)*k/2+k+1;
	k%=45678;
	printf("%lld\n",k);
	return 0;
}
