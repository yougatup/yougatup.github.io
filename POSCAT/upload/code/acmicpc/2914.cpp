#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a,l;
	double i;
	cin>>a>>l;
	for(i=1;i<100000;i++)
	{
		if(ceil(i/a)==l)
		{
			cout<<(int)i<<endl;
			break;
		}
	}
	return 0;
}
