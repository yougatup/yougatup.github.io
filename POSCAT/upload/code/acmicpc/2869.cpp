#include <iostream>

using namespace std;

int main()
{
	long long int a,b,v;
	cin>>a>>b>>v;
	cout<<1+(v-a)/(a-b)+((v-a)%(a-b)!=0)<<endl;
	return 0;
}
