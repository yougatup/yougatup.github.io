#include <iostream>
#include <string>

using namespace std;

int d[501][500]={0};
int maxi=0;

int main()
{
	string a;
	int i,j,len,k;

	cin>>a;

	for(i=0,len=a.size();i+1<len;i++)
		if((a[i]=='a' && a[i+1]=='t')||(a[i]=='g' && a[i+1]=='c'))
			d[2][i]=2;

	for(i=3;i<=len;i++)
	{
		for(j=0;j+i-1<len;j++)
		{
			if((a[j]=='a' && a[j+i-1]=='t')||(a[j]=='g' && a[j+i-1]=='c'))
				d[i][j]=d[i-2][j+1]+2;
			if(d[i][j]<d[i-1][j])
				d[i][j]=d[i-1][j];
			if(d[i][j]<d[i-1][j+1])
				d[i][j]=d[i-1][j+1];

			for(k=2;i-k>=2;k++)
				if(d[i][j]<d[k][j]+d[i-k][j+k])
					d[i][j]=d[k][j]+d[i-k][j+k];

			if(d[i][j]>maxi)
				maxi=d[i][j];
		}
	}

	cout<<maxi<<endl;
	return 0;
}
