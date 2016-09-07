#include <cstdio>

using namespace std;

bool isPal(int num)
{
	char s[10];
	int len=0,i;
	while(num!=0)
	{
		s[len++]=num%10;
		num/=10;
	}
	for(i=0;i<len/2;i++)
		if(s[i]!=s[len-i-1])
			return false;
	return true;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	if(n<=2)
	{
		printf("2\n");
		return 0;
	}
	for(i=n+(n%2==0);true;i+=2)
	{
		if(!isPal(i))
			continue;
		if(i%2==0)
			continue;
		for(j=3;j*j<=i;j+=2)
			if(i%j==0)
				break;
		if(j*j>i)
		{
			printf("%d\n",i);
			break;
		}
	}

	return 0;
}
