#include <iostream>

using namespace std;

int main()
{
	int i,j,n;

	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
			cout<<" ";
		for(j=0;j<2*i+1;j++)
			cout<<"*";
		cout<<endl;
	}
	return 0;
}
