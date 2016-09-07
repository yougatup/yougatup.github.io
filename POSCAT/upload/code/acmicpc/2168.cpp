#include <cstdio>

using namespace std;

long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	long long int a,b,g;
	scanf("%lld %lld",&a,&b);
	g=gcd(a,b);
	a/=g;
	b/=g;
	printf("%lld\n",(a+b-1)*g);
	return 0;
}
