#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x1,y1,r1,x2,y2,r2;
	double d;
	int t;

	cin>>t;
	while(t-->0)
	{
		cin>>x1>>y1>>r1>>x2>>y2>>r2;

		if(x1==x2 && y1==y2 && r1==r2)
		{
			cout<<-1<<endl;
			continue;
		}
		d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(d>r1+r2)
			cout<<0<<endl;
		else if(d==r1+r2)
			cout<<1<<endl;
		else
		{
			if(max(r1,r2)<min(r1,r2)+d)
				cout<<2<<endl;
			else if(max(r1,r2)==min(r1,r2)+d)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}

	return 0;
}
