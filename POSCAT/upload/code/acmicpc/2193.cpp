#include <iostream>

using namespace std;

long long int arr[100][2];

int main()
{
	int n,i;
	cin>>n;
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	arr[2][0]=1;
	arr[2][1]=0;
	for(i=3;i<=n;i++)
	{
		arr[i][0]=arr[i-1][0]+arr[i-1][1];
		arr[i][1]=arr[i-1][0];
	}
	cout<<arr[n][0]+arr[n][1]<<endl;
	return 0;
}
