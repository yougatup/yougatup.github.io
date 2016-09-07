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
	int a,b,c,d;// a/b and c/d
	int za,mo;
	int ggg;

	cin>>a>>b>>c>>d;
	za=a*d+b*c;
	mo=b*d;
	ggg=gcd(za,mo);	

	cout<<za/ggg<<" "<<mo/ggg<<endl;

	return 0;
}
