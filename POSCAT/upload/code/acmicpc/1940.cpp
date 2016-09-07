#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int>::iterator it;

int main()
{
	int n,m,i,cnt=0;
	scanf("%d %d",&n,&m);
	v.resize(n);
	for(it=v.begin();it!=v.end();it++)
		scanf("%d",it);
	sort(v.begin(),v.end());

	for(it=v.begin();;)
	{
		i=*it;
		it++;
		if(it==v.end() || i>m/2)
			break;
		if(binary_search(it,v.end(),m-i))
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
