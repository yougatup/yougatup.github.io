#include <iostream>

using namespace std;

int gidung[1010];
int le[1010];
int ri[1010];

int main()
{
	int n,i,maxi;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>maxi;
		cin>>gidung[maxi];
	}
	maxi=0;
	for(i=0;i<=1000;i++)
	{
		if(gidung[i]>maxi)
			maxi=gidung[i];
		le[i]=maxi;
	}
	maxi=0;
	for(i=1000;i>=0;i--)
	{
		if(gidung[i]>maxi)
			maxi=gidung[i];
		ri[i]=maxi;
	}
	maxi=0;
	for(i=0;i<=1000;i++)
	{
		if(le[i]>ri[i])
			maxi+=ri[i];
		else
			maxi+=le[i];
	}
	cout<<maxi<<endl;
	return 0;
}
