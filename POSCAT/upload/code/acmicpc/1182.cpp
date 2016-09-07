#include <cstdio>

using namespace std;

int set[20],n,s,cnt=0,c=0;

void find(int index,int sum)
{
	if(index==n)
	{
		if(sum==s)
			cnt++;
		return;
	}
	find(index+1,sum);
	find(index+1,sum+set[index]);
}

int main()
{
	int i;
	scanf("%d %d",&n,&s);
	for(i=0;i<n;i++)
		scanf("%d",&set[i]);
	if(s==0)
		cnt--;
	find(0,0);
	printf("%d\n",cnt);
	return 0;
}
