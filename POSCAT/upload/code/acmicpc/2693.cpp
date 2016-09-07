#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t,a[10],sum=0,i;
	cin>>t;
	while(t-->0)
	{
		for(i=0;i<10;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+10);
		cout<<a[7]<<endl;
	}
	return 0;
}
