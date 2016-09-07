#include <cstdio>

using namespace std;

int main()
{
	int rec[4][4];
	int n,i,j,k,cnt=0,a,b;
	bool map[110][110]={false};

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		for(j=1;j<=10;j++)
			for(k=1;k<=10;k++)
				map[a+j][b+k]=true;
	}

	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			if(map[i][j])
				cnt++;

	printf("%d\n",cnt);

	return 0;
}
