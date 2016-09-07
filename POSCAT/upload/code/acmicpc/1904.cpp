#include <cstdio>

int arr[3][2];

int main()
{
	int n,i;
	scanf("%d",&n);
	arr[0][0]=1;
	arr[0][1]=0;
	arr[1][0]=0;
	arr[1][1]=1;

	for(i=1;i<n;i++)
	{
		arr[2][0]=(arr[0][0]+arr[0][1])%15746;
		arr[2][1]=(arr[1][0]+arr[1][1])%15746;
		arr[0][0]=arr[1][0];
		arr[0][1]=arr[1][1];
		arr[1][0]=arr[2][0];
		arr[1][1]=arr[2][1];
	}
	printf("%d\n",(arr[1][0]+arr[1][1])%15746);

	return 0;
}
