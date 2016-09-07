#include <cstdio>

using namespace std;

int tree[10010][2];
bool root[10010]={false};
int minmax[10010][2]={0};
int cnt=1;
int hm=0;

void inorder(int index,int height)
{
	if(index==-1)
		return;
	if(height>hm)
		hm=height;
	inorder(tree[index][0],height+1);
	if(minmax[height][0]==0)
		minmax[height][0]=cnt;
	minmax[height][1]=cnt++;
	inorder(tree[index][1],height+1);
}


int main()
{
	int n;
	int i,a,b,c;
	int r,maxi=0,maxw=0;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		tree[a][0]=b;
		tree[a][1]=c;
		if(b!=-1)
			root[b]=true;
		if(c!=-1)
			root[c]=true;
	}
	for(i=1;i<=n;i++)
	{
		if(!root[i])
		{
			r=i;
			break;
		}
	}

	inorder(r,1);

	for(i=1;i<=hm;i++)
	{
		if(maxw<minmax[i][1]-minmax[i][0]+1)
		{
			maxw=minmax[i][1]-minmax[i][0]+1;
			maxi=i;
		}
	}

	printf("%d %d\n",maxi,maxw);

	return 0;
//////

}
