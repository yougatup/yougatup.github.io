#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string dan[]={"kg","g","l","lb"};
double ch[]={2.2046,3.7854,0.2642,0.4536};

int main()
{
	int t,i;
	double so;
	string in;
	cin>>t;
	while(t--)
	{
		cin>>so>>in;
		for(i=0;i<4;i++)
			if(dan[i]==in)
				break;
		printf("%.4lf ",so*ch[i]);
		cout<<dan[3-i]<<endl;
	}

	return 0;
}
