#include <cstdio>

using namespace std;

int main()
{
	int num[10]={0};
	int maxi=0,n;

	scanf("%d",&n);
	while(n!=0)
	{
		num[n%10]++;
		n/=10;
	}
	for(n=0;n<10;n++)
	{
		if(n==6 || n==9)
			continue;
		if(maxi<num[n])
			maxi=num[n];
	}
	if(maxi<(num[6]+num[9]+1)/2)
		maxi=(num[6]+num[9]+1)/2;

	printf("%d\n",maxi);

	return 0;
}
