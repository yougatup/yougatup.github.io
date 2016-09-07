#include <iostream>

using namespace std;

int prime[20000]={2,3,5};
int pnum=3;
long long int r,g,gc;
int yak[1000][2]={0};
int ynum=0;

long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	if(a<b)
		return gcd(b,a);
	return gcd(b,a%b);
}

void find(long long int accum,int index)
{
	if(index==ynum)
		return;

	int i,j;
	for(i=0;i<yak[index][1];i++)
	{
		accum*=yak[index][0];
		cout<<accum<<" "<<r/accum<<" "<<g/accum<<endl;
		for(j=index+1;j<ynum;j++)
			find(accum,j);
	}
}

int main()
{
	int i,j;
	long long int tmp;
	for(i=7;i<31623;i++)
	{
		for(j=0;j<pnum;j++)
			if(i%prime[j]==0)
				break;
		if(j==pnum)
			prime[pnum++]=i;
	}
	cin>>r>>g;
	tmp=gc=gcd(r,g);
	cout<<1<<" "<<r<<" "<<g<<endl;
	if(tmp==1)
		return 0;
	for(i=0;i<pnum && tmp!=1;i++)
	{
		if(tmp%prime[i]!=0)
			continue;
		yak[ynum][0]=prime[i];
		while(tmp%prime[i]==0)
		{
			yak[ynum][1]++;
			tmp/=prime[i];
		}
		ynum++;
	}
	if(tmp!=1)
	{
		cout<<tmp<<" "<<r/tmp<<" "<<g/tmp<<endl;
		return 0;
	}
	for(i=0;i<ynum;i++)
		find(1,i);
	return 0;
}
