#include <iostream>

using namespace std;

int bound[20];

int print(int line)
{
	if(line==0)
	{
		cout<<"*";
		return 1;
	}
	else if(line==1)
	{
		cout<<"* *";
		return 3;
	}
	else if(line==2)
	{
		cout<<"*****";
		return 5;
	}
	int i,j,res;
	for(i=14;i>=0;i--)
		if(line>=bound[i])
			break;
	res=print(line-bound[i]);
	for(j=0;j<2*line+1-2*res;j++)
		cout<<" ";
	print(line-bound[i]);
	return 2*line+1;
}

int main()
{
	int n,i,j;
	bound[0]=3;
	for(i=1;i<15;i++)
		bound[i]=2*bound[i-1];
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)
			cout<<" ";
		print(i);
		for(j=1;j<n-i;j++)
			cout<<" ";
		cout<<endl;
	}
	return 0;
}
