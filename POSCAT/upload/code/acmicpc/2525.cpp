#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(b+c>=60)
		cout<<(a+(b+c)/60)%24<<" ";
	else
		cout<<a<<" ";
	cout<<(b+c)%60<<endl;
	return 0;
}
