#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
	int i;
	int g;
	int s;
	int b;
} Con;

Con c[1000];

bool comp(const Con& a,const Con& b)
{
	if(a.g==b.g)
	{
		if(a.s==b.s)
			return a.b>b.b;
		return a.s>b.s;
	}
	return a.g>b.g;
}

int main()
{
	int n,k,i,cur=0;

	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d %d %d %d",&c[i].i,&c[i].g,&c[i].s,&c[i].b);
	sort(c,c+n,comp);

	for(i=0;c[i].i!=k;i++)
	{
		if((i<n-1) && (c[i].g==c[i+1].g) && (c[i].s==c[i+1].s) && (c[i].b==c[i+1].b))
			cur++;
		else
			cur=0;
	}
	printf("%d\n",i+1-cur);
	return 0;
}
