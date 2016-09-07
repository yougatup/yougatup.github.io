#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
	int a;
	int b;
} Point;

Point line[100];
int lis[100];

bool comp(const Point& a,const Point& b)
{
	return a.a<b.a;
}

int main()
{
	int n,i,j,a,b;
	int maxi=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",&line[i].a,&line[i].b);
	sort(line,line+n,comp);
	
	for(i=0;i<n;i++)
	{
		lis[i]=1;
		for(j=0;j<n;j++)
		{
			if(line[j].b<line[i].b && lis[j]+1>lis[i])
				lis[i]=lis[j]+1;
		}
		if(maxi<lis[i])
			maxi=lis[i];
	}

	printf("%d\n",n-maxi);

	return 0;
}
