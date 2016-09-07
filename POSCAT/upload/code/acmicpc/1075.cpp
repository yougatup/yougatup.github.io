#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long int n,f,i;
	cin>>n>>f;
	n-=n%100;
	for(i=0;i<100;i++)
	{
		if((n+i)%f==0)
		{
			printf("%02d\n",(int)i);
			break;
		}
	}
	return 0;
}
