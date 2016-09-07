#include <iostream>

using namespace std;

int main()
{
	int n,tmp,cnt;
	cin>>n;
	cnt=0;
	tmp=n;
	do
	{
		cnt++;
		tmp=(tmp%10)*10+(tmp%10+tmp/10)%10;
	}while(n!=tmp);

	cout<<cnt<<endl;

	return 0;
}
