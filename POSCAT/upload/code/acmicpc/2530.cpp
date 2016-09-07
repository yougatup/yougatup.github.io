#include <iostream>

using namespace std;

int main()
{
	int h,m,s,x;
	cin>>h>>m>>s>>x;
	x+=s;
	s=x%60;
	x/=60;
	x+=m;
	m=x%60;
	x/=60;
	h=(x+h)%24;
	cout<<h<<" "<<m<<" "<<s<<endl;
	return 0;
}
