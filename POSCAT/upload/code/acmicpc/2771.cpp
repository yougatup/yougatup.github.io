#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	int x,i,len;
	string in;

	cin>>t;
	while(t-->0)
	{
		cin>>x>>in;
		for(i=0,len=in.size();i<len;i++)
		{
			if(i+1!=x)
				cout<<in[i];
		}
		cout<<endl;
	}
	return 0;
}
