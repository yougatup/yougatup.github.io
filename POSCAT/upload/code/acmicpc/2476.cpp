#include <iostream>
#include <cmath>

using namespace std;

int reward(int a,int b,int c)
{
	if(a==b && b==c)
		return 10000+a*1000;
	if(a==b)
		return 1000+a*100;
	if(b==c)
		return 1000+b*100;
	if(a==c)
		return 1000+c*100;
	return max(a,max(b,c))*100;
}

int main()
{
	int n,a,b,c,i;
	int maxi=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		if(maxi<reward(a,b,c))
			maxi=reward(a,b,c);
	}
	cout<<maxi<<endl;
	return 0;
}
