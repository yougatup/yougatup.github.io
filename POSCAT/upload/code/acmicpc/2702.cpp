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
	int t,a,b,g;
	cin>>t;
	while(t-->0)
	{
		cin>>a>>b;
		g=gcd(a,b);
		cout<<a*b/g<<" "<<g<<endl;
	}
	return 0;
}
