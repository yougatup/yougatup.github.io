#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int a;
	int ind;
} Array;

Array arr[100];
bool comp(const Array& a,const Array& b)
{
	return a.a<b.a;
}

int main()
{
	int n,i,j;
	int min;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i].a;
		arr[i].ind=i;
	}
	stable_sort(arr,arr+n,comp);

	for(i=0;i<n;i++)
	{
		min=-1;
		for(j=0;j<n;j++)
		{
			if(arr[j].ind==i)
			{
				cout<<j<<" ";
				break;
			}
		}
	}
	cout<<endl;

	return 0;
}
