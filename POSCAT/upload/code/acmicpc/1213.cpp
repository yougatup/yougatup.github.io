#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int c[150]={0};
	int i,j,len,hol=0;

	cin>>s;
	for(i=0,len=s.size();i<len;i++)
		c[s[i]]++;

	for(i='A';i<='Z';i++)
	{
		if(c[i]%2==1)
		{
			if(hol==0)
				hol=i;
			else
			{
				cout<<"I\'m Sorry Hansoo"<<endl;
				return 0;
			}
		}
	}

	for(i='A';i<='Z';i++)
		for(j=0;j<c[i]/2;j++)
			cout<<(char)i;
	if(hol!=0)
		cout<<(char)hol;
	for(i='Z';i>='A';i--)
		for(j=0;j<c[i]/2;j++)
			cout<<(char)i;
	cout<<endl;
	return 0;
}
