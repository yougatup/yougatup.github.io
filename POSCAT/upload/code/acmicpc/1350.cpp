#include <cstdio>

using namespace std;

int main()
{
	int n;
	long long int arr[1000];
	long long int clu,i,sum=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	scanf("%lld",&clu);
	for(i=0;i<n;i++)
		sum+=arr[i]/clu+(arr[i]%clu!=0);
	printf("%lld\n",sum*clu);
	return 0;
}
