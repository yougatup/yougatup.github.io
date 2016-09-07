#include <iostream>

using namespace std;

int main()
{
	int n[110]={0};
	int s,i,j,x;
	cin>>s;
	for(i=0;i<s;i++)
	{
		cin>>x;
		for(j=i-1;j>=x;j--)
			n[j+1]=n[j];
		n[j+1]=i+1;
	}
	for(i=s-1;i>=0;i--)
		cout<<n[i]<<" ";
	cout<<endl;
	return 0;
}
