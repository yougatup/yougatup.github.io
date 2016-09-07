#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    long long int a=0,b=0,c=1;
    int n;
 
    cin>>n;
 
    for(;n>0;n--)
    {
        a=b;
        b=c;
        c=a+b;
    }
 
    printf("%d\n",b);
 
    return 0;
}

