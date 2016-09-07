#include <iostream>

using namespace std;

int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	if(a<b)
		return gcd(b,a);
	return gcd(b,a%b);
}

int main()
{
	long long int n,a,b;
	cin>>n;
	while(n-->0)
	{
		cin>>a>>b;
		cout<<(a*b)/gcd(a,b)<<endl;
	}
	return 0;
}
