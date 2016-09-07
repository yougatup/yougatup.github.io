#include <iostream>
#include <string>

using namespace std;

int hex2dec(string hex)
{
	int i,len=hex.size();
	int sum=0;
	for(i=0;i<len;i++)
	{
		sum*=16;
		if(hex[i]>='A' && hex[i]<='F')
			sum+=hex[i]-'A'+10;
		if(hex[i]>='0' && hex[i]<='9')
			sum+=hex[i]-'0';
	}
	return sum;
}

int main()
{
	string in;
	cin>>in;
	cout<<hex2dec(in)<<endl;

	return 0;
}
