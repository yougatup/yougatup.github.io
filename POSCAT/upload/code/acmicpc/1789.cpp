#include <iostream>

using namespace std;

int main()
{
	long long int i,n,s=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s+=i;
		if(s>n)
			break;
	}
	cout<<i-1<<endl;
	return 0;
}
