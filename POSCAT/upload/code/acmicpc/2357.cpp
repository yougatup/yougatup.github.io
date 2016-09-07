#include <iostream>
#include <cstdio>

using namespace std;

int minarr[300000];
int maxarr[300000];
int arr[100000];
int cnt=1;

void build(int index)
{
	if(index>=cnt && index<2*cnt)
		return;

	build(2*index);
	build(2*index+1);

	if(minarr[2*index]>minarr[2*index+1])
		minarr[index]=minarr[2*index+1];
	else
		minarr[index]=minarr[2*index];

	if(maxarr[2*index]>maxarr[2*index+1])
		maxarr[index]=maxarr[2*index];
	else
		maxarr[index]=maxarr[2*index+1];
}

int minSearch(int bmin,int bmax,int smin,int smax,int index)
{
	if(smin<=bmin && bmax<=smax)
		return minarr[index];
	if(smax<=bmin || bmax<=smin)
		return 1000000001;
	int mid=(bmax+bmin)/2;
	int left = minSearch(bmin,mid,smin,smax,2*index);
	int right = minSearch(mid,bmax,smin,smax,2*index+1);
	if(left>right)
		return right;
	else
		return left;
}

int maxSearch(int bmin,int bmax,int smin,int smax,int index)
{
	if(smin<=bmin && bmax<=smax)
		return maxarr[index];
	if(smax<=bmin || bmax<=smin)
		return 0;
	int mid=(bmax+bmin)/2;
	int left = maxSearch(bmin,mid,smin,smax,2*index);
	int right = maxSearch(mid,bmax,smin,smax,2*index+1);
	if(left>right)
		return left;
	else
		return right;
}

int main()
{
	int n,m;
	int i,a,b;

	cin>>n>>m;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	while(cnt<n)
		cnt*=2;
	for(i=0;i<cnt;i++)
	{
		if(i<n)
		{
			minarr[i+cnt]=arr[i];
			maxarr[i+cnt]=arr[i];
		}
		else
		{
			minarr[i+cnt]=1000000001;
			maxarr[i+cnt]=0;
		}
	}
	build(1);

	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;
		cout<<minSearch(0,cnt,a,b,1)<<" "<<maxSearch(0,cnt,a,b,1)<<endl;
	}

	return 0;
}
