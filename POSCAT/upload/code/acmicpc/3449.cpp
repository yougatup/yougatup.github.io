#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a,b;
	int t,i,len,cnt;

	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cnt=0;
		for(i=0,len=a.size();i<len;i++)
			if(a[i]!=b[i])
				cnt++;
		cout<<"Hamming distance is "<<cnt<<"."<<endl;
	}
	return 0;
}
