#include <iostream>
#include <string>

using namespace std;

string s[50][5];

int main()
{
	int n,i,j,k,l,cnt=50,cur,aa,bb;

	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<5;j++)
			cin>>s[i][j];

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			cur=0;
			for(k=0;k<5;k++)
				for(l=0;l<7;l++)
					if(s[i][k][l]!=s[j][k][l])
						cur++;
			if(cur<cnt)
			{
				cnt=cur;
				aa=i+1;
				bb=j+1;
			}
		}

	cout<<aa<<" "<<bb<<endl;

	return 0;
}
