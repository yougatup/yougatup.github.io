#include <cstdio>

using namespace std;

int box[1000];
int lis[1000];

int main()
{
	int n,i,j,cur,maxi=0;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&box[i]);

	lis[0]=1;
	for(i=1;i<n;i++)
	{
		cur=1;
		for(j=0;j<i;j++)
		{
			if(lis[j]>=cur && box[j]<box[i])
				cur=lis[j]+1;
		}
		lis[i]=cur;
		if(cur>maxi)
			maxi=cur;
	}

	printf("%d\n",maxi);

	return 0;
}
