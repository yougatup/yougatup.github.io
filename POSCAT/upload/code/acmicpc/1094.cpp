#include <cstdio>

using namespace std;

int main()
{
	int x,cnt=0;
	scanf("%d",&x);
	while(x!=0)
	{
		cnt+=x%2;
		x/=2;
	}
	printf("%d\n",cnt);
	return 0;
}
