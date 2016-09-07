#include <cstdio>

using namespace std;

int a[100001][3];

int main()
{
	int n,i;
	scanf("%d",&n);
	a[1][0]=1;
	a[1][1]=1;
	a[1][2]=1;

	for(i=2;i<=n;i++)
	{
		a[i][0]=a[i-1][0]+a[i-1][1]+a[i-1][2];
		a[i][1]=a[i-1][0]+a[i-1][2];
		a[i][2]=a[i-1][0]+a[i-1][1];
		a[i][0]%=9901;
		a[i][1]%=9901;
		a[i][2]%=9901;
	}

	printf("%d\n",(a[n][0]+a[n][1]+a[n][2])%9901);

	return 0;
}
