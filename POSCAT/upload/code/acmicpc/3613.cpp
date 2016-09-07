#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string in;
	bool isC=true,isJ=true;
	int i,len;

	cin>>in;
	if(!(isalpha(in[0]) && islower(in[0])))
	{
		cout<<"Error!"<<endl;
		return 0;
	}
	for(i=0,len=in.size();i<len;i++)
	{
		if(in[i]=='_')
		{
			isJ=false;
			if(i+1==len)
			{
				cout<<"Error!"<<endl;
				return 0;
			}
			if(in[i+1]=='_')
			{
				cout<<"Error!"<<endl;
				return 0;
			}
		}
		if(isupper(in[i]))
			isC=false;
	}

	if(!isC && !isJ)
	{
		cout<<"Error!"<<endl;
		return 0;
	}
	if(isC && isJ)
	{
		cout<<in<<endl;
		return 0;
	}

	if(isC)
	{
		for(i=0;i<len;i++)
		{
			if(in[i]=='_')
			{
				if(i+1!=len)
					cout<<(char)toupper(in[i+1]);
				i++;
			}
			else
				cout<<in[i];
		}
		cout<<endl;
	}
	else
	{
		for(i=0;i<len;i++)
		{
			if(isupper(in[i]))
				cout<<"_"<<(char)tolower(in[i]);
			else
				cout<<in[i];
		}
		cout<<endl;
	}
	return 0;
}
