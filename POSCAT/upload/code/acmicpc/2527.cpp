#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int a[2][2];
	int b[2][2];
	int c[2][2];
	int i,j;

	while(scanf("%d",&a[0][0])!=EOF)
	{
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				if(i==j && j==0)
					continue;
				else
					scanf("%d",&a[i][j]);
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				scanf("%d",&b[i][j]);
		c[0][0]=max(a[0][0],b[0][0]);
		c[0][1]=max(a[0][1],b[0][1]);
		c[1][0]=min(a[1][0],b[1][0]);
		c[1][1]=min(a[1][1],b[1][1]);
		if(c[0][0]>c[1][0] || c[0][1]>c[1][1])
			printf("d\n");
		else if(c[0][0]==c[1][0] && c[0][1]==c[1][1])
			printf("c\n");
		else if(c[0][0]==c[1][0] || c[0][1]==c[1][1])
			printf("b\n");
		else
			printf("a\n");
	}

	return 0;
}
