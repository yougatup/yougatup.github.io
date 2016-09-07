#include <iostream>

using namespace std;

int main()
{
	int i,maxi=0,cur=0,in,out;
	for(i=0;i<10;i++)
	{
		cin>>in>>out;
		cur+=out;
		cur-=in;
		if(cur>maxi)
			maxi=cur;
	}
	cout<<maxi<<endl;
	return 0;
}
