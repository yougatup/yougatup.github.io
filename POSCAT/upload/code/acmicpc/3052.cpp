#include <iostream>

using namespace std;

int main()
{
	int a[42]={0};
	int i,cnt=0,in;

	for(i=0;i<10;i++)
	{
		cin>>in;
		a[in%42]++;
	}

	for(i=0;i<42;i++)
		if(a[i]!=0)
			cnt++;

	cout<<cnt<<endl;
	return 0;
}
