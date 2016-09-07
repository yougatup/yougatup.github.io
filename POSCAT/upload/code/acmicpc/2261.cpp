#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
	int x;
	int y;
} Point;

Point p[100010]={};
int n;

int find(int s,int e)
{
	if(s>=e-1)
		return 100000001;
	else if(s==e-2)
		return (p[s].x-p[s+1].x)*(p[s].x-p[s+1].x)+(p[s].y-p[s+1].y)*(p[s].y-p[s+1].y);

	int le,ri,mid=(s+e)/2,fini;
	int res,tmp,i,j;
	le=find(s,mid);
	ri=find(mid,e);
	if(le>ri)
		res=ri;
	else
		res=le;
	for(i=(mid-12>s?mid-12:s);i<mid;i++)
	{
		for(j=mid,fini=(mid+12<e?mid+12:e),fini=(fini<i+12?fini:i+12);j<fini;j++)
		{
			tmp=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
			if(res>tmp)
				res=tmp;
		}
	}
	return res;
}

bool comp(const Point& a,const Point& b)
{
	return a.x < b.x;
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",&p[i].x,&p[i].y);
	sort(p,p+n,comp);
	printf("%d\n",find(0,n));
	return 0;
}
