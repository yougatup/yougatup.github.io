#include <iostream>
#include <cstdio>

using namespace std;

int tree[30][2];

void preorder(int index)
{
	if(index==-1)
		return;
	printf("%c",'A'+index);
	preorder(tree[index][0]);
	preorder(tree[index][1]);
}

void inorder(int index)
{
	if(index==-1)
		return;
	inorder(tree[index][0]);
	printf("%c",'A'+index);
	inorder(tree[index][1]);
}

void postorder(int index)
{
	if(index==-1)
		return;
	postorder(tree[index][0]);
	postorder(tree[index][1]);
	printf("%c",'A'+index);
}

int main()
{
	int n,i;
	char p,c1,c2;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>p>>c1>>c2;
		if(c1!='.')
			tree[p-'A'][0]=c1-'A';
		else
			tree[p-'A'][0]=-1;
		if(c2!='.')
			tree[p-'A'][1]=c2-'A';
		else
			tree[p-'A'][1]=-1;
	}
	preorder(0);
	cout<<endl;
	inorder(0);
	cout<<endl;
	postorder(0);
	cout<<endl;

	return 0;
////
}
