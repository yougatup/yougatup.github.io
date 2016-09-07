#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

#define MAX_LENGTH 510

using namespace std;

class bigInt {
public:
	int data[MAX_LENGTH];
	int num;
	bool neg;

	bigInt()
	{
		int i;
		for(i=0;i<MAX_LENGTH;i++)
			data[i]=0;
		num=0;
		neg=false;
	}

	bigInt& operator=(bigInt a)
	{
		int i;
		num=a.num;
		neg=a.neg;
		for(i=0;i<num;i++)
			data[i]=a.data[i];
		return *this;
	}

	bigInt& operator=(int a)
	{
		num=0;
		if(a<0)
		{
			neg=true;
			a*=(-1);
		}
		else
			neg=false;
		while(a!=0)
		{
			data[num++]=a%10000;
			a/=10000;
		}
		return *this;
	}

	bool comp(bigInt a,bigInt b)
	{
		int i;
		for(i=(a.num>b.num?a.num:b.num)-1;i>=0;i--)
			if(a.data[i]>b.data[i])
				return false;
			else if(a.data[i]<b.data[i])
				return true;
		return false;
	}

	bigInt sum(bigInt a,bigInt b)
	{
		int i,carry=0;
		bigInt tmp;
		tmp.num=(a.num>b.num?a.num:b.num);
		for(i=0;i<tmp.num;i++)
		{
			tmp.data[i]=a.data[i]+b.data[i]+carry;
			carry=tmp.data[i]/10000;
			tmp.data[i]%=10000;
		}
		if(carry>0)
			tmp.data[tmp.num++]=carry;
		while(tmp.num>1 && tmp.data[tmp.num-1]==0)
			tmp.num--;
		return tmp;
	}

	bigInt sub(bigInt a,bigInt b)
	{
		int i,carry=0;
		bigInt tmp;
		tmp.num=a.num;
		for(i=0;i<tmp.num;i++)
		{
			tmp.data[i]=a.data[i]-b.data[i]-carry;
			if(tmp.data[i]<0)
			{
				carry=1;
				tmp.data[i]=10000+tmp.data[i];
			}
			else
				carry=0;
		}
		while(tmp.num>1 && tmp.data[tmp.num-1]==0)
			tmp.num--;
		return tmp;
	}

	bigInt operator+(bigInt a)
	{
		bigInt tmp;

		if(neg==a.neg)
		{
			tmp=sum(*this,a);
			tmp.neg=neg;
		}
		else
		{
			if(comp(*this,a))
			{
				tmp=sub(a,*this);
				tmp.neg=a.neg;
			}
			else
			{
				tmp=sub(*this,a);
				tmp.neg=neg;
			}
		}
		return tmp;
	}

	bigInt operator*(bigInt a)
	{
		bigInt tmp;
		int i,j,carry;

		tmp.neg=(neg!=a.neg);
		
		for(i=0;i<num;i++)
		{
			carry=0;
			for(j=0;j<a.num;j++)
			{
				tmp.data[i+j]+=data[i]*a.data[j]+carry;
				carry=tmp.data[i+j]/10000;
				tmp.data[i+j]%=10000;
			}
			while(carry!=0)
			{
				tmp.data[i+j]=carry%10000;
				carry/=10000;
				j++;
			}
			if(i+j>tmp.num)
				tmp.num=i+j;
		}
		while(tmp.num>1 && tmp.data[tmp.num-1]==0)
			tmp.num--;
		return tmp;
	}

	bigInt operator-(bigInt a)
	{
		bigInt tmp;
		a.neg=!a.neg;
		tmp=(*this)+a;
		return tmp;
	}

	friend istream& operator>>(istream &in, bigInt &bi)
	{
		string s;
		int i;
		in>>s;
		if(s[0]=='-')
		{
			bi.neg=true;
			s=s.substr(1);
		}
		else
			bi.neg=false;
		bi.num=0;
		for(i=s.size()-1;i>3;i-=4)
			bi.data[bi.num++]=atoi(s.substr(i-3,4).c_str());
		bi.data[bi.num++]=atoi(s.substr(0,i+1).c_str());
		return in;
	}

	friend ostream& operator<<(ostream &out, bigInt &bi)
	{
		int i;
		if(bi.neg && !(bi.num==1 && bi.data[0]==0))
			out<<"-";
		out<<bi.data[bi.num-1];
		for(i=bi.num-2;i>=0;i--)
			out<<(bi.data[i]/1000)<<((bi.data[i]/100)%10)<<((bi.data[i]/10)%10)<<(bi.data[i]%10);
		return out;
	}
};

int main()
{
	bigInt a,b;
	bigInt ad,su,mu;

	cin>>a>>b;

	ad=a+b;
	su=a-b;
	mu=a*b;

	cout<<ad<<endl;
	cout<<su<<endl;
	cout<<mu<<endl;

	return 0;
}
