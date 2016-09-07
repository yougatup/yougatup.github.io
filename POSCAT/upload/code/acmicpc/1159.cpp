#include <iostream>

using namespace std;

int main()
{
	int num[200]={0};
	int n,i;
	string s;
	bool f=false;

	cin>>n;
	while(n-->0)
	{
		cin>>s;
		num[s[0]]++;
	}
	for(i='a';i<='z';i++)
	{
		if(num[i]>=5)
		{
			cout<<(char)i;
			f=true;
		}
	}
	if(!f)
		cout<<"PREDAJA";
	cout<<endl;
	return 0;
}
