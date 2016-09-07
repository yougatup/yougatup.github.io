#include <string>
#include <iostream>

using namespace std;

string pass,cry;

int main()
{
	int i,len,plen;
	getline(cin,pass);
	getline(cin,cry);

	for(i=0,len=pass.size(),plen=cry.size();i<len;i++)
	{
		if(pass[i]==' ')
			continue;
		pass[i]=(26+pass[i]-cry[i%plen]-1)%26+'a';
	}

	cout<<pass<<endl;

	return 0;
}
