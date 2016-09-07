#include <iostream>

using namespace std;

int main()
{
	int t,x;
	bool beau[10];
	int cnt,i;

	cin>>t;
	while(t-->0)
	{
		cin>>x;
		cnt=0;
		for(i=0;i<10;i++)
			beau[i]=true;
		while(x!=0)
		{
			if(beau[x%10])
			{
				cnt++;
				beau[x%10]=false;
			}
			x/=10;
		}
		cout<<cnt<<endl;
	}

	return 0;
}
