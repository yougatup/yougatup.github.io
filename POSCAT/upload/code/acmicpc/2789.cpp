#include <iostream>
#include <string>

using namespace std;

int main()
{
	string in,cam("CAMBRIDGE");
	int i,j,len1,len2;
	bool flag;

	cin>>in;
	len2=cam.size();
	for(i=0,len1=in.size();i<len1;i++)
	{
		flag=true;
		for(j=0;j<len2;j++)
		{
			if(in[i]==cam[j])
				flag=false;
		}
		if(flag)
			cout<<in[i];
	}
	cout<<endl;

	return 0;
}
