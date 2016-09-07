#include <iostream>

using namespace std;

int main()
{
	int sum=0,i,a;

	for(i=0;i<5;i++)
	{
		cin>>a;
		if(a>40)
			sum+=a;
		else
			sum+=40;
	}
	cout<<sum/5<<endl;
	return 0;
}
