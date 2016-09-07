#include <iostream>
#include <string>

using namespace std;

int d[4000][4000]={0};

int main()
{
	string a,b;
	int i,j,la,lb,maxi=0;

	cin>>a>>b;
	la=a.size();
	lb=b.size();

	if(a[0]==b[0])
		d[0][0]=1;
	maxi=d[0][0];
	for(i=1;i<la;i++)
		if(a[i]==b[0])
		{
			d[i][0]=1;
			maxi=1;
		}
	for(j=1;j<lb;j++)
	{
		if(a[0]==b[j])
		{
			d[0][j]=1;
			maxi=1;
		}
	}

	for(i=1;i<la;i++)
	{
		for(j=1;j<lb;j++)
		{
			if(a[i]==b[j])
			{
				d[i][j]=d[i-1][j-1]+1;
				if(d[i][j]>maxi)
					maxi=d[i][j];
			}
			else
				d[i][j]=0;
		}
	}

	cout<<maxi<<endl;
	return 0;
}
