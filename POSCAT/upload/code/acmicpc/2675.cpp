#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	int r,i,j,len;
	string s;

	cin>>t;
	while(t--)
	{
		cin>>r>>s;
		for(i=0,len=s.size();i<len;i++)
			for(j=0;j<r;j++)
				cout<<s[i];
		cout<<endl;
	}
	return 0;
}
