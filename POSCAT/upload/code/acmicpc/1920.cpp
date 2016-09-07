#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[100010];

bool search(int start,int end,int find)
{
	if(end-start<1)
		return false;
	if(end-start==1)
	{
		if(a[start]==find)
			return true;
		else
			return false;
	}
	int mid=(start+end)/2;

	if(a[mid]>find)
		return search(start,mid,find);
	else
		return search(mid,end,find);
}

int main()
{
	int n,m,i;
	int x;

	cin>>n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	cin>>m;
	while(m-->0)
	{
		scanf("%d",&x);
		if(search(0,n,x))
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
