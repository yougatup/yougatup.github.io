#include <iostream>

using namespace std;

int k[10];

void build()
{
	int i;
	k[0]=1;
	for(i=1;i<10;i++)
		k[i]=3*k[i-1];
}
bool check(int x)
{
	int i;
	for(i=0;i<10;i++)
		if(k[i]<=(x%(3*k[i])) && (x%(3*k[i]))<2*k[i])
			return false;
	return true;
}

int main()
{
	int n;
	int i,j,x;
	bool fi,fj;
	build();
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(x=0;x<10;x++)
				if(k[x]<=(i%(3*k[x])) && (i%(3*k[x]))<2*k[x])
					if(k[x]<=(j%(3*k[x])) && (j%(3*k[x]))<2*k[x])
						break;
			if(x==10)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
