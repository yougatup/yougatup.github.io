#include <cstdio>
#include <iostream>

using namespace std;

char dung[10];
int k;
int store[10];
bool check[10]={false};
long long int mini=9999999999,maxi=0;

void find(long long int num,int index)
{
	int i;
	bool flag;
	if(index==k+1)
	{
		if(num<maxi && num>mini)
			return;
		flag=true;
		for(i=0;i<k;i++)
		{
			if((store[i]<store[i+1]) != (dung[i]=='<'))
			{
				flag=false;
				break;
			}
		}
		if(!flag)
			return;
		if(num>maxi)
			maxi=num;
		if(num<mini)
			mini=num;
	}
	for(i=0;i<10;i++)
	{
		if(!check[i])
		{
			check[i]=true;
			store[index]=i;
			find(num*10+i,index+1);
			check[i]=false;
		}
	}
}

void print(long long int num,int index)
{
	if(index==k+1)
		return;
	print(num/10,index+1);
	printf("%lld",num%10);
}

int main()
{
	int i;
	scanf("%d",&k);
	for(i=0;i<k;i++)
		cin>>dung[i];

	find(0,0);

	print(maxi,0);
	printf("\n");
	print(mini,0);
	printf("\n");

	return 0;
}
