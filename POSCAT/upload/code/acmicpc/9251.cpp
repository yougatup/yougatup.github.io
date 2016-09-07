#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int d[1000][1000];

int main()
{
	string a,b;
	int i,j,la,lb;

	cin>>a>>b;

	if(a[0]==b[0])
		d[0][0]=1;
	for(i=1,la=a.size();i<la;i++)
	{
		if(a[i]==b[0])
			d[i][0]=1;
		else
			d[i][0]=d[i-1][0];
	}
	for(j=1,lb=b.size();j<lb;j++)
	{
		if(a[0]==b[j])
			d[0][j]=1;
		else
			d[0][j]=d[0][j-1];
	}

	for(i=1;i<la;i++)
		for(j=1;j<lb;j++)
			d[i][j]=max(d[i-1][j-1]+(a[i]==b[j]),max(d[i-1][j],d[i][j-1]));

	cout<<d[la-1][lb-1]<<endl;

	return 0;
}
