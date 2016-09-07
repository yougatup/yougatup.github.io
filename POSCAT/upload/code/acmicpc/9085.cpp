#include <iostream>

using namespace std;

int main()
{
	int t,n,i,sum,tmp;
	cin>>t;
	while(t-->0)
	{
		cin>>n;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>tmp;
			sum+=tmp;
		}
		cout<<sum<<endl;
	}
	return 0;
}
