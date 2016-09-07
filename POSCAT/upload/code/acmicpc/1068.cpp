#include <iostream>

using namespace std;

bool tree[60][60]={false};
bool check[60]={false};
int child[60]={0};
int n,root;

int find(int index)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(!check[i] && tree[index][i])
		{
			check[i]=true;
			sum+=find(i);
		}
	}
	if(sum==0)
		sum++;
	child[index]=sum;
	return child[index];
}

int main()
{
	int i,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x==-1)
			root=i;
		else
		{
			tree[i][x]=true;
			tree[x][i]=true;
		}
	}
	check[root]=true;
	find(root);
	cin>>x;
	cout<<child[root]-child[x]<<endl;
	return 0;
}
