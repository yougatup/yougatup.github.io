#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int t[100000];

int main()
{
	int n,i,maxi=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);
	sort(t,t+n,greater<int>());
	for(i=0;i<n;i++)
		if(maxi<i+t[i])
			maxi=i+t[i];
	printf("%d\n",maxi+2);
	return 0;
}
