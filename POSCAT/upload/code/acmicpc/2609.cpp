#include <cstdio>
#include <iostream>
 
using namespace std;
 
int gcd(int a,int b)
{
    if(b==0)
        return a;
    if(a<b)
        return gcd(b,a);
    return gcd(b,a%b);
}
 
int main()
{
    int ggg,lll;
    int a,b;
 
    cin>>a>>b;
    ggg=gcd(a,b);
    lll=a*b/ggg;
 
    printf("%d\n%d\n",ggg,lll);
 
    return 0;
}

