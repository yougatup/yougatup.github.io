#include <cstdio>
#include <algorithm>

using namespace std;

int a[200000];
int b[200000];
int na,nb,cnt=0;

int main()
{
	int i,j;
	scanf("%d %d",&na,&nb);
	for(i=0;i<na;i++)
		scanf("%d",&a[i]);
	for(i=0;i<nb;i++)
		scanf("%d",&b[i]);
	sort(a,a+na);
	sort(b,b+nb);

	for(i=j=0;i<na && j<nb;)
	{
		if(a[i]==b[j])
		{
			i++;
			j++;
			cnt--;
		}
		else if(a[i]>b[j])
			j++;
		else
			i++;
		cnt++;
	}
	while(i++<na)
		cnt++;
	while(j++<nb)
		cnt++;
	printf("%d\n",cnt);
	return 0;
}
