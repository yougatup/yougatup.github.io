#include <iostream>

using namespace std;

int main()
{
	int h,m;
	cin>>h>>m;
	if(m<45)
		cout<<(h+23)%24<<" ";
	else
		cout<<h<<" ";
	cout<<(m+15)%60<<endl;
	return 0;
}
