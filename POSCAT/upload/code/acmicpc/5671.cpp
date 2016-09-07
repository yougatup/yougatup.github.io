#include <cstdio>

using namespace std;

bool isBan(int i)
{
	bool check[10]={false};
	while(i!=0)
	{
		if(check[i%10])
			return false;
		check[i%10]=true;
		i/=10;
	}
	return true;
}

int main()
{
	int n,m;
	int i,cnt;

	while(scanf("%d %d",&n,&m)!=EOF)
	{
		cnt=0;
		for(i=n;i<=m;i++)
			if(isBan(i))
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
