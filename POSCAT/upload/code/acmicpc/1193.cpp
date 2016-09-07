#include <cstdio>

using namespace std;

int main()
{
	int x;
	int i,sum=0;

	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		sum+=i;
		if(x<=sum)
			break;
	}
	sum-=i;
	if(i%2==0)
		printf("%d/%d\n",x-sum,i-(x-sum)+1);
	else
		printf("%d/%d\n",i-(x-sum)+1,x-sum);
	return 0;
}
