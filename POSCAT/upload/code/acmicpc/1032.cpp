#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string res,in;
	int i,j,len;

	cin>>n>>res;
	len=res.size();
	for(i=1;i<n;i++)
	{
		cin>>in;
		for(j=0;j<len;j++)
		{
			if(res[j]=='?')
				continue;
			if(res[j]!=in[j])
				res[j]='?';
		}
	}
	cout<<res<<endl;

	return 0;
}
