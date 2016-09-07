#include <iostream>

using namespace std;

int main()
{
	int num[1500];
	int cnt=0;
	int i,j;
	int sum=0;
	int a,b;

	for(i=1;i<50;i++)
	{
		for(j=0;j<i;j++)
			num[cnt++]=i;
		if(cnt>1000)
			break;
	}

	cin>>a>>b;

	for(i=a-1;i<b;i++)
		sum+=num[i];

	cout<<sum<<endl;

	return 0;
}
