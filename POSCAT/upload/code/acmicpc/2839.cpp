#include <iostream>

using namespace std;

int main()
{
	int n;
	int sug[5050];
	int i;
	cin>>n;
	for(i=3;i<=n;i++)
		sug[i]=1000000;
	sug[3]=1;
	sug[5]=1;

	for(i=3;i<=n;i++)
	{
		if(sug[i+3]>sug[i]+1)
			sug[i+3]=sug[i]+1;
		if(sug[i+5]>sug[i]+1)
			sug[i+5]=sug[i]+1;
	}
	if(sug[n]==1000000)
		cout<<-1<<endl;
	else
		cout<<sug[n]<<endl;

	return 0;
}
