#include <cstdio>

using namespace std;

int par[100001]={0};
int n,d;

int seper(int x)
{
	int cnt=0;
	while(x>d)
	{
		cnt+=x/d;
		x=x/d+x%d;
	}
	return cnt;
}

int main()
{
	int i,tmp;
	int cnt=0;
	scanf("%d %d",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		par[tmp]++;
	}
	for(i=0;i<=n;i++)
	{
		if(par[i]>d)
			cnt+=seper(par[i]);
	}
	printf("%d\n",cnt);
	return 0;
}
