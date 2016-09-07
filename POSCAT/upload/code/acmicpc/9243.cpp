#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,i,len;
	string a,b;

	cin>>n>>a>>b;
	for(i=0,len=a.size();i<len;i++)
		if((a[i]==b[i])==(n%2==1))
		{
			cout<<"Deletion failed"<<endl;
			return 0;
		}
	cout<<"Deletion succeeded"<<endl;
	return 0;
}
