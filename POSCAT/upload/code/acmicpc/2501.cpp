#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    int n,k;
    int i;
 
    cin>>n>>k;
 
    for(i=1;i<=n;i++)
    {
        if(n%i!=0)
            continue;
        k--;
        if(k==0)
        {
            printf("%d\n",i);
            break;
        }
    }
    if(i==n+1)
        printf("0\n");
 
    return 0;
}

