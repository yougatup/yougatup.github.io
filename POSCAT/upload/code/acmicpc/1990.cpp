#include <cstdio>

using namespace std;

int prime[1500]={2,3,5,7};
int pnum=4;

bool isPal(int num)
{
	int s[10];
	int len=0,i;
	while(num!=0)
	{
		s[len++]=num%10;
		num/=10;
	}
	for(i=0;i<len/2;i++)
		if(s[i]!=s[len-i-1])
			return false;
	return true;
}

bool search(int s,int e,int num)
{
	if(s>=e)
		return false;
	else if(s==e-1)
	{
		if(prime[s]==num)
			return true;
		else
			return false;
	}
	int mid=(s+e)/2;
	if(prime[mid]>num)
		return search(s,mid,num);
	else
		return search(mid,e,num);
}

int main()
{
	int a,b,i,j;
	bool flag;

	for(i=11;i<10000;i+=2)
	{
		flag=true;
		for(j=0;j<pnum && prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0)
			{
				flag=false;
				break;
			}
		if(flag)
			prime[pnum++]=i;
	}
	
	scanf("%d %d",&a,&b);
	for(i=a;i<=b && i<=9989899;i++)
	{
		if(!isPal(i))
			continue;
		if(i>prime[pnum-1])
		{
			flag=true;
			for(j=0;j<pnum && prime[j]*prime[j]<=i;j++)
				if(i%prime[j]==0)
				{
					flag=false;
					break;
				}
			if(flag)
				printf("%d\n",i);
		}
		else if(search(0,pnum,i))
			printf("%d\n",i);
	}
	printf("-1\n");
	return 0;
}
