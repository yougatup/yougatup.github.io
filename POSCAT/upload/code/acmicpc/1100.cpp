#include <iostream>
#include <string>

using namespace std;

int main()
{
	string chess[8];
	int i,j;
	int sum=0;

	for(i=0;i<8;i++)
		cin>>chess[i];

	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(chess[i][j]=='F' && (i+j)%2==0)
				sum++;
	cout<<sum<<endl;

	return 0;
}
