#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A[100];
	int B[100];
	int n,i;
	int sum=0;

	cin>>n;

	for(i=0;i<n;i++)
		cin>>A[i];
	for(i=0;i<n;i++)
		cin>>B[i];

	sort(A,A+n,greater<int>());
	sort(B,B+n);

	for(i=0;i<n;i++)
		sum+=A[i]*B[i];

	cout<<sum<<endl;

	return 0;
}
