#include <cstdio>

using namespace std;

int main()
{
	int n,d,k,c;
	int cho[3000]={0};
	int state[30000];
	int i,j,maxi,cur;

	scanf("%d %d %d %d",&n,&d,&k,&c);
	for(i=0;i<n;i++)
		scanf("%d",&state[i]);
	cur=0;
	for(i=0;i<k;i++)
	{
		cho[state[i]-1]++;
		if(cho[state[i]-1]==1)
			cur++;
	}
	maxi=cur;
	if(cho[c-1]==0)
		maxi++;
	for(i=1;i<n;i++)
	{
		cho[state[i-1]-1]--;
		if(cho[state[i-1]-1]==0)
			cur--;
		cho[state[(i+k-1)%n]-1]++;
		if(cho[state[(i+k-1)%n]-1]==1)
			cur++;
		if(maxi<cur+(cho[c-1]==0))
			maxi=cur+(cho[c-1]==0);
	}
	printf("%d\n",maxi);
	return 0;
}
