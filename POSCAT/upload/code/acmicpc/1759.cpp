#include <iostream>
#include <algorithm>

using namespace std;

int cnt=0;
char pass[20];
int l,c;
int vnum=0,cnum=0;
bool check[20];

bool isvowel(char ch)
{
	return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

void find(int index)
{
	if(cnt==l)
	{
		if(vnum<1 || cnum<2)
			return;
		for(int i=0;i<c;i++)
			if(check[i])
				cout<<pass[i];
		cout<<endl;
		return;
	}
	if(index==c)
		return;

	check[index]=true;
	cnt++;
	if(isvowel(pass[index]))
		vnum++;
	else
		cnum++;
	find(index+1);

	check[index]=false;
	cnt--;
	if(isvowel(pass[index]))
		vnum--;
	else
		cnum--;
	find(index+1);
}

int main()
{
	int i;
	cin>>l>>c;
	for(i=0;i<c;i++)
		cin>>pass[i];
	sort(pass,pass+c);
	find(0);

	return 0;
}
