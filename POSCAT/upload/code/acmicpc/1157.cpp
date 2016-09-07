#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a[30]={0};
	string input;
	int i,len;
	int max,index;
	cin>>input;
	len=input.size();
	for(i=0;i<len;i++)
	{
		if(input[i]<='Z' && input[i]>='A')
			a[input[i]-'A']++;
		else
			a[input[i]-'a']++;
	}
	max=0;
	if(max==0)
		index=-1;
	for(i=0;i<26;i++)
	{
		if(max==a[i])
			index=-1;
		else if(max<a[i])
		{
			index=i;
			max=a[i];
		}
	}
	if(index==-1)
		printf("?\n");
	else
		printf("%c\n",index+'A');

	return 0;
///////
}
