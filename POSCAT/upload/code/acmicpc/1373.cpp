#include <iostream>
#include <string>

using namespace std;

int bin2oct(char a,char b,char c)
{
	return 4*(a=='1')+2*(b=='1')+(c=='1');
}

int main()
{
	int i,len;
	string in;
	
	cin>>in;
	len=in.size();
	if(len%3==0)
		i=0;
	else if(len%3==1)
	{
		cout<<bin2oct('0','0',in[0]);
		i=1;
	}
	else
	{
		cout<<bin2oct('0',in[0],in[1]);
		i=2;
	}
	for(;i<len;i+=3)
		cout<<bin2oct(in[i],in[i+1],in[i+2]);
	cout<<endl;

	return 0;
}
