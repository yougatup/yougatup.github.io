#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int s[100000];
int main()
{
	int n,i,j,r=2000000001,t;
	int a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);
	sort(s,s+n);
	for(i=0,j=n-1;i<j;)
	{
		t=s[i]+s[j];
		if(abs(r)>abs(t))
		{
			r=t;
			a=s[i];
			b=s[j];
		}
		if(t>0)
			j--;
		else
			i++;
	}
	printf("%d %d\n",a,b);
}
