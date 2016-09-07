#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	int a,b,c,i=1;
	while(true)
	{
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0)
			break;
		if(i!=1)
			cout<<endl;
		cout<<"Triangle #"<<i++<<endl;
		if(a==-1)
		{
			if(b*b>=c*c)
				cout<<"Impossible."<<endl;
			else
				printf("a = %.3lf\n",(double)sqrt(c*c-b*b));
		}
		else if(b==-1)
		{
			if(a*a>=c*c)
				cout<<"Impossible."<<endl;
			else
				printf("b = %.3lf\n",(double)sqrt(c*c-a*a));
		}
		else
			printf("c = %.3lf\n",(double)sqrt(a*a+b*b));
	}
	return 0;
}
