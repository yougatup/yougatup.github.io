#include <iostream>

using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	if(a<b)
		return gcd(b,a);
	return gcd(b,a%b);
}

int main()
{
	int n,a,b;
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		cout<<a*b/gcd(a,b)<<endl;
	}
	return 0;
}
