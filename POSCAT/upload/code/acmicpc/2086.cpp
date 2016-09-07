#include <cstdio>

using namespace std;

long long int mat[100][2][2]={{{1,0},{0,-1}},{{1,1},{1,0}}};
long long int dan=1000000000;

void cal(long long int x,int index,long long int accum[2][2])
{
	if(x==0)
		return;
	cal(x/2,index+1,accum);
	if(x%2)
	{
		long long int tmp[2][2];
		tmp[0][0]=accum[0][0]*mat[index][0][0]+accum[0][1]*mat[index][1][0];
		tmp[0][1]=accum[0][0]*mat[index][0][1]+accum[0][1]*mat[index][1][1];
		tmp[1][0]=tmp[0][1];
		tmp[1][1]=accum[1][0]*mat[index][0][1]+accum[1][1]*mat[index][1][1];
		accum[0][0]=tmp[0][0]%dan;
		accum[0][1]=tmp[0][1]%dan;
		accum[1][0]=tmp[1][0]%dan;
		accum[1][1]=tmp[1][1]%dan;
	}
	return;
}

int main()
{
	long long int a,b;
	long long int an[2][2]={{1,0},{0,1}},bn[2][2]={{1,0},{0,1}};
	int i;
	for(i=2;i<65;i++)
	{
		mat[i][0][0]=mat[i-1][0][0]*mat[i-1][0][0]+mat[i-1][0][1]*mat[i-1][1][0];
		mat[i][0][1]=mat[i-1][0][0]*mat[i-1][0][1]+mat[i-1][0][1]*mat[i-1][1][1];
		mat[i][1][0]=mat[i][0][1];
		mat[i][1][1]=mat[i-1][0][1]*mat[i-1][1][0]+mat[i-1][1][1]*mat[i-1][1][1];
		mat[i][0][0]%=dan;
		mat[i][0][1]%=dan;
		mat[i][1][0]%=dan;
		mat[i][1][1]%=dan;
	}
	scanf("%lld %lld",&a,&b);
	a+=1;
	b+=2;
	cal(a,1,an);
	cal(b,1,bn);
	printf("%lld\n",(dan+bn[0][1]-an[0][1])%dan);
	return 0;
}
