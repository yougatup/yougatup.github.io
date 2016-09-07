#include <iostream>
#include <string>

using namespace std;

int main()
{
	string cup;
	int i,len,h=10;

	cin>>cup;
	for(i=1,len=cup.size();i<len;i++)
	{
		if(cup[i]!=cup[i-1])
			h+=10;
		else
			h+=5;
	}
	cout<<h<<endl;

	return 0;
//
}
