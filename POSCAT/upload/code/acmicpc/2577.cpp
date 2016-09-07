#include <iostream>

using namespace std;

int num[10]={0};

int main()
{
	int a,b,c;
	int mul;
	int i;
	cin>>a>>b>>c;
	mul=a*b*c;
	while(mul!=0)
	{
		num[mul%10]++;
		mul/=10;
	}
	for(i=0;i<10;i++)
		cout<<num[i]<<endl;
	return 0;
}
