#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    int i,j;
     
    scanf("%d",&n);
    for(i=n;i>0;i--)
    {
        for(j=n-1;j>=i;j--)
            printf(" ");
        for(j=0;j<i;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}

