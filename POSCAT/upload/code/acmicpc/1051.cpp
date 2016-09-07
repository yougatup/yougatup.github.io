#include <iostream>

using namespace std;

int main()
{
	int arr[100][100];
	int n,m,i,j,k,max=0;
	int a,b;
	char c;

	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>c;
			arr[i][j]=c-'0';
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k+i<n && k+j<m;k++)
			{
				a=k+i;
				b=k+j;
				if((k+1)>max && arr[i][j]==arr[a][b] && arr[i][b]==arr[a][j] && arr[i][b]==arr[i][j])
					max=k+1;
			}
		}
	}
	cout<<max*max<<endl;
	return 0;
}
