#include <iostream>

using namespace std;

int main()
{
	int n,i,j;
	int h[55],w[55],s[55]={0};

	cin>>n;
	for(i=0;i<n;i++)
		cin>>h[i]>>w[i];

	for(i=0;i<n;i++)
	{
		s[i]=1;
		for(j=0;j<n;j++)
		{
			if(h[j]>h[i] && w[j]>w[i])
				s[i]++;
		}
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}
