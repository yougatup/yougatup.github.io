#include <iostream>
#include <string>

using namespace std;

int main()
{
	string in;
	int i,len;
	cin>>in;
	cout<<in[0];
	for(i=1,len=in.size();i<len;i++)
	{
		if(in[i]=='-')
			cout<<in[i+1];
	}
	cout<<endl;
}
