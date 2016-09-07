#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10000];
int num=0;

int main()
{
	int a,b,c,d;
	int mini;

	for(a=1;a<10;a++)
	{
		for(b=1;b<10;b++)
		{
			for(c=1;c<10;c++)
			{
				for(d=1;d<10;d++)
				{
					mini=1000*a+100*b+10*c+d;
					if(mini>1000*b+100*c+10*d+a)
						mini=1000*b+100*c+10*d+a;
					if(mini>1000*c+100*d+10*a+b)
						mini=1000*c+100*d+10*a+b;
					if(mini>1000*d+100*a+10*b+c)
						mini=1000*d+100*a+10*b+c;
					arr[num++]=mini;
				}
			}
		}
	}
	sort(arr,arr+num);

	scanf("%d %d %d %d",&a,&b,&c,&d);
	mini=1000*a+100*b+10*c+d;
	if(mini>1000*b+100*c+10*d+a)
		mini=1000*b+100*c+10*d+a;
	if(mini>1000*c+100*d+10*a+b)
		mini=1000*c+100*d+10*a+b;
	if(mini>1000*d+100*a+10*b+c)
		mini=1000*d+100*a+10*b+c;
	b=1;
	for(a=0;a<num;a++)
	{
		if(arr[a]<mini)
		{
			if(a==0)
				b++;
			else if(arr[a-1]!=arr[a])
				b++;
		}
	}

	printf("%d\n",b);

	return 0;
}
