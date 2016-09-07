#include <iostream>

using namespace std;

int main()
{
	int t,i,x;
	cin>>t;
	for(i=0;i<9;i++)
	{
		cin>>x;
		t-=x;
	}
	cout<<t<<endl;
	return 0;
}
