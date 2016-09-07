#include <iostream>
#include <string>

using namespace std;

int d[100][100][100]={0};

int main()
{
	string a,b,c;
	int i,j,k,la,lb,lc;

	cin>>a>>b>>c;
	la=a.size();
	lb=b.size();
	lc=c.size();

	if(a[0]==b[0] && a[0]==c[0])
		d[0][0][0]=1;

	for(i=1;i<la;i++)
		if(a[i]==b[0] && a[i]==c[0])
			d[i][0][0]=1;
		else
			d[i][0][0]=d[i-1][0][0];

	for(j=1;j<lb;j++)
		if(a[0]==b[j] && a[0]==c[0])
			d[0][j][0]=1;
		else
			d[0][j][0]=d[0][j-1][0];

	for(k=1;k<lc;k++)
		if(a[0]==b[0] && a[0]==c[k])
			d[0][0][k]=1;
		else
			d[0][0][k]=d[0][0][k-1];

	for(i=1;i<la;i++)
		for(j=1;j<lb;j++)
		{
			if(a[i]==b[j] && a[i]==c[0])
				d[i][j][0]=1;
			if(d[i][j][0]<d[i-1][j][0])
				d[i][j][0]=d[i-1][j][0];
			if(d[i][j][0]<d[i][j-1][0])
				d[i][j][0]=d[i][j-1][0];
		}

	for(j=1;j<lb;j++)
		for(k=1;k<lc;k++)
		{
			if(a[0]==b[j] && a[0]==c[k])
				d[0][j][k]=1;
			if(d[0][j][k]<d[0][j-1][k])
				d[0][j][k]=d[0][j-1][k];
			if(d[0][j][k]<d[0][j][k-1])
				d[0][j][k]=d[0][j][k-1];
		}

	for(k=1;k<lc;k++)
		for(i=1;i<la;i++)
		{
			if(a[i]==b[0] && a[i]==c[k])
				d[i][0][k]=1;
			if(d[i][0][k]<d[i-1][0][k])
				d[i][0][k]=d[i-1][0][k];
			if(d[i][0][k]<d[i][0][k-1])
				d[i][0][k]=d[i][0][k-1];
		}

	for(i=1;i<la;i++)
		for(j=1;j<lb;j++)
			for(k=1;k<lc;k++)
			{
				if(a[i]==b[j] && a[i]==c[k])
					d[i][j][k]=d[i-1][j-1][k-1]+1;
				if(d[i][j][k]<d[i-1][j][k])
					d[i][j][k]=d[i-1][j][k];
				if(d[i][j][k]<d[i][j-1][k])
					d[i][j][k]=d[i][j-1][k];
				if(d[i][j][k]<d[i][j][k-1])
					d[i][j][k]=d[i][j][k-1];
			}

	cout<<d[la-1][lb-1][lc-1]<<endl;

	return 0;
}
