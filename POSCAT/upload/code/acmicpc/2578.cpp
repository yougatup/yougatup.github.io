#include <iostream>

using namespace std;

int main()
{
	int bingo[5][5];
	bool check[5][5]={false};
	int i,j,cnt,k,sum,num;
	bool flagh,flagv,flagl,flagr;

	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			cin>>bingo[i][j];
	for(cnt=1;cnt<=25;cnt++)
	{
		cin>>num;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(bingo[i][j]==num)
					check[i][j]=true;
		sum=0;
		flagl=flagr=true;
		for(i=0;i<5;i++)
		{
			flagl&=check[i][i];
			flagr&=check[i][4-i];
			flagh=flagv=true;
			for(j=0;j<5;j++)
			{
				flagh&=check[i][j];
				flagv&=check[j][i];
			}
			if(flagh)
				sum++;
			if(flagv)
				sum++;
		}
		if(flagr)
			sum++;
		if(flagl)
			sum++;
		if(sum>=3)
		{
			cout<<cnt<<endl;
			break;
		}
	}
	return 0;
}
