#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s;
	int i,len,sum;
	bool arr[150];
	cin>>n;
	while(n--)
	{
		cin>>s;
		for(i='A';i<='Z';i++)
			arr[i]=true;
		sum=0;
		for(i=0,len=s.size();i<len;i++)
			arr[s[i]]=false;
		for(i='A';i<='Z';i++)
			if(arr[i])
				sum+=i;
		cout<<sum<<endl;
	}
	return 0;
}
