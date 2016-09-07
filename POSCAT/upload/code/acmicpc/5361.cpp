#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	double a,b,c,d,e;
	cin>>t;
	while(t-->0)
	{
		cin>>a>>b>>c>>d>>e;
		printf("$%.2lf\n",a*350.34+b*230.90+c*190.55+d*125.30+e*180.90);
	}
	return 0;
}
