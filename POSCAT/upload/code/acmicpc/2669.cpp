#include <cstdio>

using namespace std;

int main()
{
	int rec[4][4];
	int i,j,k,cnt=0;
	bool map[110][110]={false};

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&rec[i][j]);

	for(i=0;i<4;i++)
		for(j=rec[i][0]+1;j<=rec[i][2];j++)
			for(k=rec[i][1]+1;k<=rec[i][3];k++)
				map[j][k]=true;

	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			if(map[i][j])
				cnt++;

	printf("%d\n",cnt);

	return 0;
}
