#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int i,len;
	string s;
	cin>>s;
	for(i=0,len=s.size();i<len;i++)
		if(s[i]<'a')
			s[i]+=32;
		else
			s[i]-=32;
	cout<<s<<endl;
	return 0;
}
