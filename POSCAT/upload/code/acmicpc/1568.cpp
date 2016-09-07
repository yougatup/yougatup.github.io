#include <iostream>

using namespace std;

int main()
{
	int n,i,cnt=0;

	cin>>n;

	i=1;
	while(n!=0)
	{
		if(n<i)
			i=1;
		n-=i;
		cnt++;
		i++;
	}
	cout<<cnt<<endl;
	return 0;
}
