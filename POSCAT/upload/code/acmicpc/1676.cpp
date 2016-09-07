#include <iostream>

using namespace std;

int main()
{
	int i,tmp,n,cnt=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		tmp=i;
		while(tmp%5==0)
		{
			tmp/=5;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
