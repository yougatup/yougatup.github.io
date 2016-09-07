#include <iostream>
#include <string>

using namespace std;

int main()
{
	string in;
	int t,i,v,s,len;

	cin>>t;
	while(t-->0)
	{
		cin>>in;
		v=s=0;
		for(i=0,len=in.size();i<len;i++)
		{
			if(in[i]=='O')
				v++;
			else
				v=0;
			s+=v;
		}
		cout<<s<<endl;
	}
	return 0;
}
