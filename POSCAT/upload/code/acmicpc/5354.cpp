#include <iostream>

using namespace std;

int main()
{
	int t,J,i,j;

	cin>>t;
	while(t-->0)
	{
		cin>>J;
		for(i=0;i<J;i++)
		{
			for(j=0;j<J;j++)
			{
				if(i==0 || j==0 || i==J-1 || j==J-1)
					cout<<"#";
				else
					cout<<"J";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
