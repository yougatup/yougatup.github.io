#include <cstdio>

using namespace std;

int stack[100000];
char out[200000];
int n,slen=0,olen=0,cur=1;

int main()
{
	int i,j,in;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		if(cur<=in)
		{
			for(j=cur;j<=in;j++)
			{
				stack[slen++]=j;
				out[olen++]='+';
			}
			cur=in+1;
		}
		if(stack[slen-1]!=in)
		{
			printf("NO\n");
			return 0;
		}
		stack[slen--];
		out[olen++]='-';
	}
	for(i=0;i<olen;i++)
		printf("%c\n",out[i]);
	return 0;
}
