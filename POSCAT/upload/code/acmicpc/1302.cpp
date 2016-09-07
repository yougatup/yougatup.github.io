#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	string name;
	int cnt;
} book;

bool comp(const book& a,const book& b)
{
	if(a.cnt==b.cnt)
		return a.name<b.name;
	return a.cnt>b.cnt;
}

int main()
{
	int n,i,j;
	string tmp;
	int cnt=0;
	book b[1000];

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>tmp;
		for(j=0;j<cnt;j++)
		{
			if(b[j].name==tmp)
			{
				(b[j].cnt)++;
				break;
			}
		}
		if(j==cnt)
		{
			b[cnt].name=tmp;
			b[cnt].cnt=1;
			cnt++;
		}
	}
	sort(b,b+cnt,comp);

	cout<<b[0].name<<endl;

	return 0;
}
