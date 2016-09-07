#include <iostream>

using namespace std;

int main()
{
	int t;
	int n,i;
	int fib[45][2]={{1,0},{0,1}};

	for(i=2;i<=40;i++)
	{
		fib[i][0]=fib[i-1][0]+fib[i-2][0];
		fib[i][1]=fib[i-1][1]+fib[i-2][1];
	}

	cin>>t;
	while(t-->0)
	{
		cin>>n;
		cout<<fib[n][0]<<" "<<fib[n][1]<<endl;
	}
	return 0;
}
