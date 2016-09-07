#include <cstdio>

using namespace std;

int main()
{
	int box[100][100];
	int t,i,j,m,n,sum,cnt;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&box[i][j]);
		sum=0;
		for(j=0;j<n;j++)
		{
			cnt=0;
			for(i=m-1;i>=0;i--)
			{
				if(box[i][j]==1)
				{
					sum+=(m-1-i-cnt);
					cnt++;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
