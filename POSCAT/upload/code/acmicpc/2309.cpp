#include <iostream>
#include <algorithm>

using namespace std;

bool check[10];
int nanzang[10];

bool find(int index)
{
	if(index==9)
	{
		int i,cnt=0,sum=0;
		for(i=0;i<9;i++)
		{
			if(check[i])
			{
				cnt++;
				sum+=nanzang[i];
			}
		}
		if(cnt==7 && sum==100)
		{
			for(i=0;i<9;i++)
				if(check[i])
					cout<<nanzang[i]<<endl;
			return true;
		}
		return false;
	}
	check[index]=true;
	if(find(index+1))
		return true;
	check[index]=false;
	if(find(index+1))
		return true;
	return false;
}

int main()
{
	int i;
	for(i=0;i<9;i++)
		cin>>nanzang[i];
	sort(nanzang,nanzang+9);
	find(0);
	return 0;
}
