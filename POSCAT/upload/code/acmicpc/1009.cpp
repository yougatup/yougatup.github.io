#include <iostream>

using namespace std;

int a[10][10];
int n[10];

int main()
{
	int i;
	int num;
	int t,aa,b;
	int res;

	for(i=0;i<10;i++)
	{
		a[i][0]=i;
		n[i]=1;
		num=i*i;
		while(num%10!=i)
		{
			a[i][n[i]++]=num%10;
			num*=i;
		}
	}
	
	cin>>t;
	while(t-->0)
	{
		cin>>aa>>b;
		res=a[aa%10][(b-1)%n[aa%10]];
		if(res==0)
			cout<<10<<endl;
		else
			cout<<res<<endl;
	}

	return 0;
}
