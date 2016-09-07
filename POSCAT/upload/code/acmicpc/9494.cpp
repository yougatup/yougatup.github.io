#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,i,len;
	string s;
	while(true)
	{
		cin>>n;
		if(n==0)
			break;
		i=0;
		getline(cin,s);
		while(n--)
		{
			getline(cin,s);
			for(len=s.size();i<len;i++)
				if(s[i]==' ')
					break;
		}
		cout<<i+1<<endl;
	}

	return 0;
}
