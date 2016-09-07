#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int t,i;
	char in[30];
	char c;

	scanf("%d%c",&t,&c);
	while(t-->0)
	{
		while(true)
		{
			scanf("%s",in);
			for(i=strlen(in)-1;i>=0;i--)
				printf("%c",in[i]);
			if(scanf("%c",&c)==EOF)
				break;
			if(c=='\n')
				break;
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
