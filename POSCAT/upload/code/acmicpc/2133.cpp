#include <iostream>

using namespace std;

int main()
{
	long long int arr[31][4];
	int i,n;

	arr[1][1]=0;
	arr[1][2]=2;
	arr[1][3]=0;

	arr[2][1]=2;
	arr[2][2]=0;
	arr[2][3]=3;

	for(i=3;i<=30;i++)
	{
		arr[i][1]=arr[i-1][2];
		arr[i][2]=arr[i-1][1]+2*arr[i-1][3];
		arr[i][3]=arr[i-2][3]+arr[i-1][2];
	}
	cin>>n;
	cout<<arr[n][3]<<endl;
	return 0;
}
