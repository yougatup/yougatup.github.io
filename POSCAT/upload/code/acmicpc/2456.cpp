#include <iostream>

using namespace std;

int p[4][4]={0};
int t[4]={0};

void duo(int a,int b)
{
	if(p[a][3]==p[b][3])
	{
		if(p[a][2]==p[b][2])
			cout<<0<<" "<<t[a]<<endl;
		else if(p[a][2]>p[b][2])
			cout<<a<<" "<<t[a]<<endl;
		else
			cout<<b<<" "<<t[b]<<endl;
	}
	else if(p[a][3]>p[b][3])
		cout<<a<<" "<<t[a]<<endl;
	else
		cout<<b<<" "<<t[b]<<endl;
}

void trio()
{
	if(p[1][3]==p[2][3] && p[1][3]==p[3][3])
	{
		if(p[1][2]==p[2][2] && p[1][2]==p[3][2])
			cout<<0<<" "<<t[1]<<endl;
		else if(p[1][2]==p[2][2] && p[1][2]>p[3][2])
			duo(1,2);
		else if(p[1][2]==p[3][2] && p[1][2]>p[2][2])
			duo(1,3);
		else if(p[2][2]==p[3][2] && p[2][2]>p[1][2])
			duo(2,3);
		else if(p[1][2]>p[2][2] && p[1][2]>p[3][2])
			cout<<1<<" "<<t[1]<<endl;
		else if(p[2][2]>p[1][2] && p[2][2]>p[3][2])
			cout<<2<<" "<<t[2]<<endl;
		else
			cout<<3<<" "<<t[3]<<endl;
	}
	else if(p[1][3]==p[2][3] && p[1][3]>p[3][3])
		duo(1,2);
	else if(p[1][3]==p[3][3] && p[1][3]>p[2][3])
		duo(1,3);
	else if(p[2][3]==p[3][3] && p[2][3]>p[1][3])
		duo(2,3);
	else if(p[1][3]>p[2][3] && p[1][3]>p[3][3])
		cout<<1<<" "<<t[1]<<endl;
	else if(p[2][3]>p[1][3] && p[2][3]>p[3][3])
		cout<<2<<" "<<t[2]<<endl;
	else
		cout<<3<<" "<<t[3]<<endl;
}

int main()
{
	int n,i,a,b,c;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		t[1]+=a;
		t[2]+=b;
		t[3]+=c;
		p[1][a]++;
		p[2][b]++;
		p[3][c]++;
	}
	a=1;
	b=2;
	c=3;
	if(t[a]==t[b] && t[b]==t[c])
		trio();
	else if(t[a]==t[b] && t[a]>t[c])
		duo(a,b);
	else if(t[a]==t[c] && t[a]>t[b])
		duo(a,c);
	else if(t[b]==t[c] && t[b]>t[a])
		duo(b,c);
	else if(t[a]>t[b] && t[a]>t[c])
		cout<<a<<" "<<t[a]<<endl;
	else if(t[b]>t[a] && t[b]>t[c])
		cout<<b<<" "<<t[b]<<endl;
	else
		cout<<c<<" "<<t[c]<<endl;

	return 0;
}
