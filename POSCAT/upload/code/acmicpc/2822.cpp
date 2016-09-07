#include <iostream>

using namespace std;

int main()
{
	int a[8];
	bool check[8]={false};
	int i,j,max,maxi,sum=0;
	for(i=0;i<8;i++)
		cin>>a[i];
	for(i=0;i<5;i++)
	{
		max=-1;
		for(j=0;j<8;j++)
		{
			if(check[j])
				continue;
			if(max<a[j])
			{
				max=a[j];
				maxi=j;
			}
		}
		check[maxi]=true;
		sum+=max;
	}
	cout<<sum<<endl;
	for(i=0;i<8;i++)
		if(check[i])
			cout<<i+1<<" ";
	cout<<endl;
	return 0;
}
