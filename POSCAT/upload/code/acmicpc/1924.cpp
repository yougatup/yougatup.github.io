#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x,y;
	int i,sum=0;
	string week[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	cin>>x>>y;
	for(i=1;i<x;i++)
		sum+=month[i];
	sum+=y-1;

	cout<<week[sum%7]<<endl;

	return 0;
}
