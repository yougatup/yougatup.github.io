#include <cstdio>

using namespace std;

int find(int n,int b)
{
	if(b>4)
		n++;

	if(n/10==0)
		return n;
	else
		return find(n/10,n%10)*10;
}

int main()
{
	int n;
	scanf("%d",&n);
	if(n<10)
		printf("%d\n",n);
	else
		printf("%d\n",find(n,0));
	return 0;
}
