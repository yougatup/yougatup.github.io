#include <cstdio>

using namespace std;

int main()
{
	int com[1000]={0};
	int n,i,cnt=0,in;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		if(com[in]!=0)
			cnt++;
		com[in]=1;
	}
	printf("%d\n",cnt);
	return 0;
}
