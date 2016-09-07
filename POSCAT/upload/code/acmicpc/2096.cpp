#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int maxi[3],mini[3];
	int tmp[3];
	int a,b,c;
	int n,i,j;

	scanf("%d",&n);
	for(i=0;i<3;i++)
	{
		scanf("%d",&maxi[i]);
		mini[i]=maxi[i];
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		tmp[0]=max(maxi[0],maxi[1])+a;
		tmp[1]=max(maxi[0],max(maxi[1],maxi[2]))+b;
		tmp[2]=max(maxi[1],maxi[2])+c;
		for(j=0;j<3;j++)
			maxi[j]=tmp[j];
		tmp[0]=min(mini[0],mini[1])+a;
		tmp[1]=min(mini[0],min(mini[1],mini[2]))+b;
		tmp[2]=min(mini[1],mini[2])+c;
		for(j=0;j<3;j++)
			mini[j]=tmp[j];
	}
	printf("%d %d\n",max(maxi[0],max(maxi[1],maxi[2])),min(mini[0],min(mini[1],mini[2])));
	return 0;
}
