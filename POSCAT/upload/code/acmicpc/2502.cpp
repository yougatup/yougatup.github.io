#include <cstdio>

using namespace std;

int main()
{
	int a,b,d,k;
	int f1,f2,f3,i;
	bool flag=false;

	scanf("%d %d",&d,&k);
	for(b=1;;b++)
	{
		for(a=1;a<=b;a++)
		{
			f1=a;
			f2=b;
			for(i=3;i<=d;i++)
			{
				f3=f1+f2;
				f1=f2;
				f2=f3;
			}
			if(f2==k)
			{
				flag=true;
				break;
			}
		}
		if(flag)
			break;
	}

	printf("%d\n%d\n",a,b);
	return 0;
}
