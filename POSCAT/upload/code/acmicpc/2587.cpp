#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[5],sum=0,i;
	for(i=0;i<5;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+5);
	cout<<sum/5<<endl;
	cout<<a[2]<<endl;
	return 0;
}
