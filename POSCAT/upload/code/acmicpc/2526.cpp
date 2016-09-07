#include <iostream>

using namespace std;

int main()
{
	int cy[100]={0};
	int n,tmp,p,i=1;
	cin>>n>>p;
	if(n<100)
		cy[n]=i;
	i++;
	tmp=n;
	while(true)
	{
		tmp=(tmp*n)%p;
		if(cy[tmp]!=0)
		{
			cout<<(i-cy[tmp])<<endl;
			break;
		}
		cy[tmp]=i++;
	}
	return 0;
}
