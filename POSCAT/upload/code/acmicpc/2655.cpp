#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

typedef struct {
	int size;
	int height;
	int weight;
	int index;
} Block;

bool comp(const Block& a,const Block& b)
{
	return a.size<b.size;
}

int main()
{
	int n;
	Block b[100];
	int i,j,maxi=0,maxind;
	int index[100];
	int lis[100];
	stack<int> st;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&b[i].size,&b[i].height,&b[i].weight);
		b[i].index=i+1;
		index[i]=i;
	}

	sort(b,b+n,comp);

	for(i=0;i<n;i++)
	{
		lis[i]=b[i].height;
		for(j=0;j<i;j++)
		{
			if(b[j].weight<b[i].weight && lis[i]<lis[j]+b[i].height)
			{
				lis[i]=lis[j]+b[i].height;
				index[i]=j;
			}
		}
		if(lis[i]>maxi)
		{
			maxi=lis[i];
			maxind=i;
		}
	}

	while(true)
	{
		st.push(b[maxind].index);
		if(index[maxind]==maxind)
			break;
		maxind=index[maxind];
	}

	printf("%d\n",st.size());
	while(!st.empty())
	{
		printf("%d\n",st.top());
		st.pop();
	}
	return 0;
}
