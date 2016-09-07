#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

typedef struct {
	string str[2];
	int index;
} DS;

bool comp(const DS& a,const DS& b)
{
	if(a.str[0]==b.str[0])
		return a.str[1]<b.str[1];
	return a.str[0]<b.str[0];
}

int main()
{
	int n,m;
	DS arr[101];
	string soo[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int i;
	scanf("%d %d",&n,&m);
	for(i=n;i<=m;i++)
	{
		if(i<10)
			arr[i-n].str[0]=soo[i];
		else
		{
			arr[i-n].str[0]=soo[i/10];
			arr[i-n].str[1]=soo[i%10];
		}
		arr[i-n].index=i;
	}
	sort(arr,arr+(m-n+1),comp);
	for(i=0;i<=m-n;i++)
	{
		if(i%10==0 && i!=0)
			printf("\n");
		printf("%d ",arr[i].index);
	}
	printf("\n");
	return 0;
}
