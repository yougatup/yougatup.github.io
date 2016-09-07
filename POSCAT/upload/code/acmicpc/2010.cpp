#include <iostream>

using namespace std;

int main()
{
	int n;
	int sum,x;
	cin>>n;
	cin>>sum;
	while(--n>0)
	{
		cin>>x;
		sum+=x-1;
	}
	cout<<sum<<endl;
	return 0;
}
