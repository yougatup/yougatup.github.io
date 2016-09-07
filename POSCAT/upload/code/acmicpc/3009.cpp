#include <iostream>

using namespace std;

int main()
{
	int point[3][2];
	int i;
	for(i=0;i<3;i++)
		cin>>point[i][0]>>point[i][1];
	if(point[0][0]==point[1][0])
		cout<<point[2][0];
	else if(point[0][0]==point[2][0])
		cout<<point[1][0];
	else
		cout<<point[0][0];
	cout<<" ";
	if(point[0][1]==point[1][1])
		cout<<point[2][1];
	else if(point[0][1]==point[2][1])
		cout<<point[1][1];
	else
		cout<<point[0][1];
	cout<<endl;

	return 0;
}
