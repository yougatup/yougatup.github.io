#include <iostream>
#include <string>

using namespace std;

int main()
{
	string in;
	int i,len,sum=0;
	
	cin>>in;
	for(i=0,len=in.size();i<len;i++)
	{
		if(in[i]>='a' && in[i]<='z')
			sum+=in[i]-'a'+1;
		else
			sum+=in[i]-'A'+27;
	}

	for(i=2;i*i<=sum;i++)
		if(sum%i==0)
			break;

	if(i*i>sum)
		cout<<"It is a prime word."<<endl;
	else
		cout<<"It is not a prime word."<<endl;

	return 0;
}
