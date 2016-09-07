#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

#define MAX_LENGTH 1000

using namespace std;

class bigInt {
public:
	int data[MAX_LENGTH];
	int num;

	bigInt()
	{
		int i;
		for(i=0;i<MAX_LENGTH;i++)
			data[i]=0;
		num=0;
	}

	bigInt& operator=(bigInt a)
	{
		int i;
		num=a.num;
		for(i=0;i<num;i++)
			data[i]=a.data[i];
		return *this;
	}

	bigInt& operator=(int a)
	{
		num=0;
		while(a!=0)
		{
			data[num++]=a%10000;
			a/=10000;
		}
		return *this;
	}

	bigInt operator+(bigInt a)
	{
		int i,carry=0;
		bigInt tmp;
		tmp.num=(num>a.num?num:a.num);
		for(i=0;i<tmp.num;i++)
		{
			tmp.data[i]=data[i]+a.data[i]+carry;
			carry=tmp.data[i]/10000;
			tmp.data[i]%=10000;
		}
		if(carry>0)
			tmp.data[tmp.num++]=carry;
		return tmp;
	}

	bigInt operator*(int a)
	{
		int i,carry=0;
		bigInt tmp;
		tmp.num=num;
		for(i=0;i<tmp.num;i++)
		{
			tmp.data[i]=data[i]*a+carry;
			carry=tmp.data[i]/10000;
			tmp.data[i]%=10000;
		}
		while(carry!=0)
		{
			tmp.data[tmp.num++]=carry%10000;
			carry/=10000;
		}
		return tmp;
	}

	friend istream& operator>>(istream &in, bigInt &bi)
	{
		string s;
		int i;
		in>>s;
		bi.num=0;
		for(i=s.size()-1;i>3;i-=4)
			bi.data[bi.num++]=atoi(s.substr(i-3,4).c_str());
		bi.data[bi.num++]=atoi(s.substr(0,i+1).c_str());
		return in;
	}

	friend ostream& operator<<(ostream &out, bigInt &bi)
	{
		int i;
		cout<<bi.data[bi.num-1];
		for(i=bi.num-2;i>=0;i--)
			cout<<(bi.data[i]/1000)<<((bi.data[i]/100)%10)<<((bi.data[i]/10)%10)<<(bi.data[i]%10);
		return out;
	}
};

int main()
{
	bigInt a,b,c;
	int n,i;

	while(scanf("%d",&n)!=EOF)
	{
		if(n==0 || n==1)
		{
			cout<<1<<endl;
			continue;
		}
		a=1;
		b=1;
		for(i=2;i<=n;i++)
		{
			c=a*2+b;
			a=b;
			b=c;
		}
		cout<<b<<endl;
	}
	return 0;
}
