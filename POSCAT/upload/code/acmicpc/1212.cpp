#include <iostream>
#include <string>
using namespace std;
string octa;
int len;
string b2o[]={"000","001","010","011","100","101","110","111"};
string b2oh[]={"0","1","10","11","100","101","110","111"};

int main()
{
	int i;
	cin>>octa;
	len=octa.size();
	
	cout<<b2oh[octa[0]-'0'];
	for(i=1;i<len;i++)
		cout<<b2o[octa[i]-'0'];
	cout<<endl;
	
	return 0;
}
