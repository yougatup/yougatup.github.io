#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

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
	string in;
	int t,pos,len;
	long long int a,b,c,d,g;
	
	cin>>t;
	while(t--)
	{
		cin>>in;
		len=in.size();
		if(in[len-1]==')')
		{
			pos=in.find("(");
			if(pos!=2)
				a=atoi(in.substr(2,pos-2).c_str());
			else
				a=0;
			b=atoi(in.substr(pos+1,len-pos-2).c_str());
			a=a*pow(10,len-pos-2)+b-a;
			b=pow(10,len-4)-pow(10,pos-2);
		}
		else
		{
			a=atoi(in.substr(2).c_str());
			b=pow(10,len-2);
		}
		g=gcd(a,b);
		a/=g;
		b/=g;

		cout<<a<<"/"<<b<<endl;
	}
	return 0;
}
