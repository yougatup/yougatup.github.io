#include <iostream>
#include <string>

using namespace std;

string par;
int len;
int index=0;
int count()
{
	int res,next;
	
	if(par[index]=='(')
	{
		index++;
		if(par[index]!=')')
		{
		res=count();
		if(res==0 || par[index]!=')')
			return 0;
		}
		else
			res=1;
		index++;
		if(index==len || par[index]==']' || par[index]==')')
			return res*2;
		next=count();
		if(next==0)
			return 0;
		else
			return res*2+next;
	}
	else if(par[index]=='[')
	{
		index++;
		if(par[index]!=']')
		{
		res=count();
		if(res==0 || par[index]!=']')
			return 0;
		}
		else
			res=1;
		index++;
		if(index==len || par[index]==']' || par[index]==')')
			return res*3;
		next=count();
		if(next==0)
			return 0;
		else
			return res*3+next;
	}
	else
		return 0;
}

int main()
{
	int res;
	cin>>par;
	len=par.size();

	cout<<count()<<endl;

	return 0;
}
