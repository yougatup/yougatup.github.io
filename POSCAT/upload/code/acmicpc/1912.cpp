#include <cstdio>

using namespace std;

int main()
{
	int n,in,maxi,cur;
	scanf("%d",&n);
	scanf("%d",&in);
	cur=maxi=in;
	while(--n)
	{
		scanf("%d",&in);
		if(cur<0)
			cur=in;
		else
			cur+=in;
		if(cur>maxi)
			maxi=cur;
	}
	printf("%d\n",maxi);
	return 0;
}
