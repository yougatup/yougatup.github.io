#include <iostream>
#include <cstdio>

using namespace std;

int pre[1010];
int in[1010];
int tree[1010][2];
int cnt;

void postorder(int index)
{
	if(index==-1)
		return;
	postorder(tree[index][0]);
	postorder(tree[index][1]);
	printf("%d ",index+1);
}

//find root [start,end)
int whoisRoot(int start,int end)
{
	int i,root;
	if(end<=start)
		return -1;
	if(end-start==1)
	{
		tree[in[start]][0]=-1;
		tree[in[start]][1]=-1;
		cnt++;
		return in[start];
	}

	for(i=start;i<end;i++)
	{
		if(in[i]==pre[cnt])
			break;
	}
	cnt++;
	tree[in[i]][0]=whoisRoot(start,i);
	tree[in[i]][1]=whoisRoot(i+1,end);
	return in[i];
}


int main()
{
	int t,n;
	int i,root;

	cin>>t;
	for(;t>0;t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>pre[i];
		for(i=0;i<n;i++)
			cin>>in[i];
		for(i=0;i<n;i++)
		{
			pre[i]--;
			in[i]--;
		}
		cnt=0;
		root=whoisRoot(0,n);
		postorder(root);
		cout<<endl;
	}
	return 0;
}
