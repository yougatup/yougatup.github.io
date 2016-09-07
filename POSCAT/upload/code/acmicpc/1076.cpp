#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

string color[]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};

int main()
{
	string i,j,k;
	int ii,jj,kk;
	cin>>i>>j>>k;
	for(ii=0;ii<10;ii++)
		if(color[ii]==i)
			break;
	for(jj=0;jj<10;jj++)
		if(color[jj]==j)
			break;
	for(kk=0;kk<10;kk++)
		if(color[kk]==k)
			break;
	if(ii==0 && jj==0)
		printf("0\n");
	else
	{
		if(ii!=0)
			printf("%d",ii);
		printf("%d",jj);
		while(kk--)
			printf("0");
		printf("\n");
	}
	return 0;
}
