#include <cstdio>
#include <algorithm>

using namespace std;

bool num[2000001]={false};

int main()
{
	int n,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		num[i+1000000]=true;
	}
	for(i=0;i<=2000000;i++)
		if(num[i])
			printf("%d\n",i-1000000);
	return 0;
}
