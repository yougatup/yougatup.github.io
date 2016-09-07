#include <iostream>

using namespace std;

int prime[10000]={2,3,5,7};
int pnum=4;

int main()
{
	int i,j;
	bool flag;
	int m,n,sum=0,min;

	for(i=11;i<10000;i++)
	{
		flag=true;
		for(j=0;j<pnum;j++)
		{
			if(i%prime[j]==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
			prime[pnum++]=i;
	}

	cin>>m>>n;
	i=-1;
	while(prime[++i]<m);
	min=prime[i];
	while(prime[i]<=n)
		sum+=prime[i++];
	cout<<sum<<endl<<min<<endl;
	return 0;
}
