#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef struct {
	double x;
	double y;
} point;

point p[30];
int t,n;
int check[30];
double mini;

double dis(point p1)
{
	return sqrt(p1.x*p1.x+p1.y*p1.y);
}

void calc()
{
	int i,c=0;
	point sum={0,0};
	for(i=0;i<n;i++)
		c+=check[i];
	if(c!=0)
		return;

	for(i=0;i<n;i++)
	{
		if(check[i]==1)
		{
			sum.x+=p[i].x;
			sum.y+=p[i].y;
		}
		else
		{
			sum.x-=p[i].x;
			sum.y-=p[i].y;
		}
	}
	if(mini>dis(sum))
		mini=dis(sum);
}

void find(int index)
{
	if(index==n)
	{
		calc();
		return;
	}
	check[index]=1;
	find(index+1);
	check[index]=-1;
	find(index+1);
}

int main()
{
	int i;
	cin>>t;
	while(t-->0)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y;
		}
		mini=10000000;
		find(0);
		printf("%.6lf\n",mini);
	}

	return 0;
}
