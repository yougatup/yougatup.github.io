#include <iostream>

using namespace std;

int main()
{
	long long int n;
	cin>>n;
	if(n%5==0 || n%5==2)
		cout<<"CY"<<endl;
	else
		cout<<"SK"<<endl;
	return 0;
}
