#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
	int t;
	int index;
} Con;

int s[100000];
Con c[100000];

bool comp(const Con& a,const Con& b)
{
	return a.t<b.t;
}

int main()
{
	int n,a,b,i;
	int cnt=0,last=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		s[i]=a;
		c[i].t=b;
		c[i].index=i;
	}
	sort(c,c+n,comp);

	for(i=0;i<n;i++)
	{
		if(s[c[i].index]>=last)
		{
			last=c[i].t;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
