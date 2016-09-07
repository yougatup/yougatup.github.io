#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a[100];
	int i;

	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[0]*a[n-1]<<endl;
	return 0;
}
