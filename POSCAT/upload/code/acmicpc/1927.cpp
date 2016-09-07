#include <cstdio>

using namespace std;

int h[100000];
int hnum=0;

void push(int num)
{
	int tmp,swap;
	h[++hnum]=num;
	tmp=hnum;
	while(tmp!=1)
	{
		if(h[tmp/2]>h[tmp])
		{
			swap=h[tmp/2];
			h[tmp/2]=h[tmp];
			h[tmp]=swap;
		}
		else
			break;
		tmp/=2;
	}
}

int pop()
{
	if(hnum==0)
		return 0;
	int res=h[1];
	int left,right,tmp=1,val;
	val=h[hnum--];
	while(2*tmp<=hnum)
	{
		left=h[2*tmp];
		if(2*tmp+1<=hnum)
			right=h[2*tmp+1];
		else
			right=0;

		if(right==0)
		{
			if(left<val)
			{
				h[tmp]=left;
				tmp=2*tmp;
			}
			else
				break;
		}
		else
		{
			if(left<val && left<=right)
			{
				h[tmp]=left;
				tmp=2*tmp;
			}
			else if(right<val && right<=left)
			{
				h[tmp]=right;
				tmp=2*tmp+1;
			}
			else
				break;
		}
	}
	h[tmp]=val;
	return res;
}

void print()
{
	int i,j=2;
	for(i=1;i<=hnum;i++)
	{
		if(i==j && i!=1)
		{
			printf("\n");
			j*=2;
		}
		printf("%d ",h[i]);
	}
	printf("\n");
}

int main()
{
	int n,in;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&in);
		if(in==0)
			printf("%d\n",pop());
		else
			push(in);
		//print();
	}
	return 0;
}
