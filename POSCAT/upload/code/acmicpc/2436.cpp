#include <iostream>

using namespace std;

long long int n,m,s,tmp;
long long int prime[10000]={2,3,5,7};
int pnum=4;
long long int yak[1000]={0};
int ynum=0;
long long int g[2]={-1};
bool check[1000]={false};

void find(int index)
{
	if(index==ynum)
	{
		long long int accum=1;
		int i;
		for(i=0;i<ynum;i++)
			if(check[i])
				accum*=yak[i];
		if(g[0]==-1 || g[0]+g[1]>accum+s/accum)
		{
			g[0]=accum;
			g[1]=s/accum;
		}
		return;
	}
	check[index]=true;
	find(index+1);
	check[index]=false;
	find(index+1);
}

int main()
{
	long long int i;
	int j;
	for(i=11;i<=10000;i++)
	{
		for(j=0;j<pnum;j++)
		{
			if(i%prime[j]==0)
				break;
		}
		if(j==pnum)
			prime[pnum++]=i;
	}
	cin>>n>>m;
	if(n==1)
	{
		cout<<n<<" "<<m<<endl;
		return 0;
	}
	s=tmp=m/n;
	for(j=0;j<pnum && tmp!=1;j++)
	{
		if(tmp%prime[j]!=0)
			continue;
		yak[ynum]=1;
		while(tmp%prime[j]==0)
		{
			tmp/=prime[j];
			yak[ynum]*=prime[j];
		}
		ynum++;
	}
	find(0);
	g[0]*=n;
	g[1]*=n;
	if(g[0]>g[1])
		cout<<g[1]<<" "<<g[0]<<endl;
	else
		cout<<g[0]<<" "<<g[1]<<endl;
	return 0;
}
