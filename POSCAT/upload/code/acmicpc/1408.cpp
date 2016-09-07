#include <cstdio>

using namespace std;

int main()
{
	int h1,m1,s1,t1;
	int h2,m2,s2,t2;
	int h,m,s,t;
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	t1=3600*h1+60*m1+s1;
	t2=3600*h2+60*m2+s2;
	if(t2<t1)
		t2+=24*3600;
	t=t2-t1;
	s=t%60;
	t/=60;
	m=t%60;
	t/=60;
	h=t;
	printf("%02d:%02d:%02d\n",h,m,s);
	return 0;
}
