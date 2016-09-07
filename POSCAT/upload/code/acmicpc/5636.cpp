#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int prime[100000]={2,3,5,7};
int pnum=4;

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
	string in;
	int i,j,len,p,num;
	bool flag;

	for(i=11;i<100000;i++)
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

	while(true)
	{
		cin>>in;
		len=in.size();
		if(len==1 && in[0]=='0')
			break;
		p=-1;
		for(j=5;j>0;j--)
		{
			for(i=0;i+j<=len;i++)
			{
				num=atoi(in.substr(i,j).c_str());
				if(p<num && search(0,pnum,num))
					p=num;
			}
			if(p!=-1)
				break;
		}
		cout<<p<<endl;
	}
	return 0;
}
