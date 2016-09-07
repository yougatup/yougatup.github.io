#include <iostream>

using namespace std;

int n,m,k;
int a[110][110];
int b[110][110];
int c[110][110]={0};

int main()
{
	int i,j,l;

	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];
	cin>>m>>k;
	for(i=0;i<m;i++)
		for(j=0;j<k;j++)
			cin>>b[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
			for(l=0;l<m;l++)
				c[i][j]+=a[i][l]*b[l][j];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
