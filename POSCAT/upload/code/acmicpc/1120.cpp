#include <string>
#include <iostream>

using namespace std;

int main()
{
	string a,b;
	int i,j,la,lb,mini=100,cur;

	cin>>a>>b;
	la=a.size();
	lb=b.size();

	for(i=0;i+la<=lb;i++)
	{
		cur=0;
		for(j=0;j<la;j++)
			if(a[j]!=b[i+j])
				cur++;
		if(cur<mini)
			mini=cur;
	}
	cout<<mini<<endl;
	return 0;
}
