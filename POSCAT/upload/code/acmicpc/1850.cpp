#include <iostream>
#include <string>

using namespace std;

long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	if(a<b)
		return gcd(b,a);
	return gcd(b,a%b);
}

int main()
{
	long long int a=0,b=0;
	int i,len;
	cin>>a>>b;
	for(i=gcd(a,b);i>0;i--)
		cout<<"1";
	cout<<endl;
	return 0;
}
