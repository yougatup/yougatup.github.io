#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int cup[3]={1};

void swap(int a,int b)
{
	int tmp;
	tmp=cup[a];
	cup[a]=cup[b];
	cup[b]=tmp;
}

int main()
{
	string in;
	int i,len;

	cin>>in;
	for(i=0,len=in.size();i<len;i++)
	{
		if(in[i]=='A')
			swap(0,1);
		else if(in[i]=='B')
			swap(1,2);
		else
			swap(0,2);
	}
	if(cup[0]==1)
		cout<<1<<endl;
	else if(cup[1]==1)
		cout<<2<<endl;
	else
		cout<<3<<endl;

	return 0;
}
