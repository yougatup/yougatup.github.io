#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	string score[]={"A+","A0","A-","B+","B0","B-","C+","C0","C-","D+","D0","D-","F"};
	float sc[]={4.3,4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.3,1.0,0.7,0.0};
	string in;
	int i;
	cin>>in;
	for(i=0;i<13;i++)
	{
		if(score[i]==in)
			printf("%.1f\n",sc[i]);
	}
	return 0;
}
