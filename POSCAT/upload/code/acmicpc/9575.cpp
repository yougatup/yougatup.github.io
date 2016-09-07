#include <iostream>

using namespace std;

bool check[90001]={false};

bool is58(int x)
{
	while(x!=0)
	{
		if(x%10!=5 && x%10!=8)
			return false;
		x/=10;
	}
	return true;
}

int main()
{
	int a[50],b[50],c[50];
	int k,l,m;
	int i,j,jj,cnt=0;
	int t;

	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>k;
		for(i=0;i<k;i++)
			cin>>a[i];
		cin>>l;
		for(i=0;i<l;i++)
			cin>>b[i];
		cin>>m;
		for(i=0;i<m;i++)
			cin>>c[i];

		for(i=0;i<=90000;i++)
			check[i]=false;

		for(i=0;i<k;i++)
			for(j=0;j<l;j++)
				for(jj=0;jj<m;jj++)
					if(is58(a[i]+b[j]+c[jj]))
						if(!check[a[i]+b[j]+c[jj]])
						{
							check[a[i]+b[j]+c[jj]]=true;
							cnt++;
						}

		cout<<cnt<<endl;
	}
	return 0;
}
