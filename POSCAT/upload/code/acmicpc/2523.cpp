#include <iostream>

using namespace std;

int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
			cout<<"*";
		cout<<endl;
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
			cout<<"*";
		cout<<endl;
	}
	return 0;
}
