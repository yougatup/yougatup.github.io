#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

long long int n,m,maxi=0,val,i;
long long int egg[1000];

int main()
{
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++)
		scanf("%lld",&egg[i]);
	sort(egg,egg+m,greater<long long int>());

	for(i=0;i<m;i++)
	{
		if(maxi<=(i+1>n?n:i+1)*egg[i])
		{
			val=egg[i];
			maxi=(i+1>n?n:i+1)*egg[i];
		}
	}
	printf("%lld %lld\n",val,maxi);
	return 0;
}
