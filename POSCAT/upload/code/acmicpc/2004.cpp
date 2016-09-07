#include <iostream>
#include <cmath>

using namespace std;

long long int check(long long int s,long long int base)
{
	long long int res=0;
	while(s>=base)
	{
		s/=base;
		res+=s;
	}
	return res;
}

int main()
{
	long long int n,m,nm;
	long long int sn=0,sm=0,snm=0;
	long long int dn=0,dm=0,dnm=0;

	cin>>n>>m;
	nm=n-m;
	sn=check(n,5);
	sm=check(m,5);
	snm=check(nm,5);
	dn=check(n,2);
	dm=check(m,2);
	dnm=check(nm,2);
	if(sn-sm-snm<dn-dm-dnm)
		cout<<sn-sm-snm<<endl;
	else
		cout<<dn-dm-dnm<<endl;

	return 0;
}
