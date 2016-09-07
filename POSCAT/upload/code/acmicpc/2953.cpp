#include <iostream>

using namespace std;

int main()
{
	int a,b,c,d;
	int maxi=0,min;
	int i;
	for(i=0;i<5;i++)
	{
		cin>>a>>b>>c>>d;
		if(a+b+c+d>maxi)
		{
			maxi=a+b+c+d;
			min=i+1;
		}
	}
	cout<<min<<" "<<maxi<<endl;
	return 0;
}
