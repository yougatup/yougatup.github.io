#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    int i,ga=1;
    int sum=0;
 
    cin>>n;
 
    for(;n>0;n--)
    {
        cin>>i;
        if(i==1)
            sum+=ga++;
        else
            ga=1;
    }
    printf("%d\n",sum);
 
    return 0;
}

