#include <cstdio>
#include <algorithm>

using namespace std;

long long int m,a[10010],s=0;
int n,cnt=0;

int main()
{
	int i,j;
	scanf("%d %lld",&n,&m);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0,j=0;true;)
	{
		if(m<=s)
		{
			if(s==m)
				cnt++;
			s-=a[j++];
		}
		else
		{
			if(i==n)
				break;
			s+=a[i++];
		}
	}
	printf("%d\n",cnt);
	return 0;
}
