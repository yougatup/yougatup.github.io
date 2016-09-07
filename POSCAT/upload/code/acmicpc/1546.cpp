#include <cstdio>

using namespace std;

int main()
{
	int n,tmp,i,maxi=0;
	float sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		sum+=tmp;
		if(maxi<tmp)
			maxi=tmp;
	}
	sum/=(n*maxi);
	sum*=100;
	printf("%.2f\n",sum);
	return 0;
}
