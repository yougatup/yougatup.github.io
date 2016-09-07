#include <cstdio>

using namespace std;

int in[1000][1000];
int nin[1000];
int out[1000][1000];
int nout[1000];
int cnt[1000];
int check[1000];

int main()
{
	int k,m,p,t;
	int maxi,a,b,cur,cc;
	int i,j;
	bool flag;

	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d %d",&t,&m,&p);
		for(i=0;i<m;i++)
			nin[i]=nout[i]=cnt[i]=check[i]=0;

		for(i=0;i<p;i++)
		{
			scanf("%d %d",&a,&b);
			a--;
			b--;
			in[b][nin[b]++]=a;
			out[a][nout[a]++]=b;
			cnt[b]++;
		}

		flag=true;
		maxi=0;
		while(flag)
		{
			flag=false;

			for(i=0;i<m;i++)
			{
				if(cnt[i]==0 && check[i]==0)
				{
					cur=0;
					for(j=0;j<nin[i];j++)
					{
						if(cur<check[in[i][j]])
						{
							cur=check[in[i][j]];
							cc=1;
						}
						else if(cur==check[in[i][j]])
							cc++;
					}
					if(cc>1)
						check[i]=cur+1;
					else
						check[i]=cur;
					if(check[i]==0)
						check[i]=1;
					for(j=0;j<nout[i];j++)
						cnt[out[i][j]]--;
					flag=true;
					if(maxi<check[i])
						maxi=check[i];
				}
			}
		}
		printf("%d %d\n",t,maxi);
	}
	return 0;
}
