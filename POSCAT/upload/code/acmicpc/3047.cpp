#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a[3];

void ab(char c)
{
	if(c=='A')
		cout<<a[0]<<" ";
	if(c=='B')
		cout<<a[1]<<" ";
	if(c=='C')
		cout<<a[2]<<" ";
}

int main()
{
	string s;

	cin>>a[0]>>a[1]>>a[2];

	sort(a,a+3);
	cin>>s;

	ab(s[0]);
	ab(s[1]);
	ab(s[2]);

	cout<<endl;

	return 0;
}
