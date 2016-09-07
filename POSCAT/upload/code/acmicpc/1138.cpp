#include <cstdio>

using namespace std;

int main()
{
	int n,in,out[10]={0};
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		j=0;
		while(in)
		{
			if(out[j]==0)
				in--;
			j++;
		}
		while(out[j]!=0)
			j++;
		out[j]=i+1;
	}
	for(i=0;i<n;i++)
		printf("%d ",out[i]);
	printf("\n");
	return 0;
}
