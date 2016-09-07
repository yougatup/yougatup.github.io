#include <iostream>
#include <cstdio>

using namespace std;

class bigNum {
public:
	int n[10];
	bigNum()
	{
		int i;
		for(i=0;i<10;i++)
			n[i]=0;
	}
	bigNum operator=(int a)
	{
		int i=0;
		while(a!=0)
		{
			n[i++]=a%10000;
			a/=10000;
		}
	}
	bigNum operator+(bigNum a)
	{
		bigNum tmp;
		int carry=0,i;
		for(i=0;i<10;i++)
		{
			tmp.n[i]=n[i]+a.n[i]+carry;
			carry=tmp.n[i]/10000;
			tmp.n[i]%=10000;
		}
		return tmp;
	}
	bigNum operator=(bigNum a)
	{
		int i;
		for(i=0;i<10;i++)
			n[i]=a.n[i];
	}
};

bigNum c[110][110];

int main()
{
	int i,j,k;
	for(i=0;i<=100;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
	}
	for(i=2;i<=100;i++)
		for(j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	cin>>i>>j;
	for(k=9;k>=0;k--)
		if(c[i][j].n[k]!=0)
			break;
	cout<<c[i][j].n[k--];
	for(;k>=0;k--)
		printf("%04d",c[i][j].n[k]);
	cout<<endl;
	return 0;
}
