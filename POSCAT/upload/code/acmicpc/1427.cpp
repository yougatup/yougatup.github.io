#include <iostream>
#include <algorithm>

using namespace std;

int arr[20];
int index=0;

void input(int in)
{
	if(in==0)
		return;
	arr[index++]=in%10;
	input(in/10);
}

int main()
{
	int in,i;
	cin>>in;
	input(in);
	sort(arr,arr+index,greater<int>());
	for(i=0;i<index;i++)
		cout<<arr[i];
	cout<<endl;

	return 0;
}
