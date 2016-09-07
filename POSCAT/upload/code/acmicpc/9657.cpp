#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	if((n-1)%7==1 || (n-1)%7==6)
		cout<<"CY"<<endl;
	else
		cout<<"SK"<<endl;
	return 0;
}
