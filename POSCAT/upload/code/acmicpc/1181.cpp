#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const string& a, const string& b)
{
	if(a.size()==b.size())
		return a<b;
	else
		return a.size()<b.size();
}

int main()
{
	int n,i;
	string arr[20010];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n,comp);
	cout<<arr[0]<<endl;
	for(i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
			cout<<arr[i]<<endl;
	}
	return 0;
}
