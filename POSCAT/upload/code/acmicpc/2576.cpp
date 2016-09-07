#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    int i,n;
    int min=101,sum=0;
 
    for(i=0;i<7;i++)
    {
        cin>>n;
        if(n%2==1)
        {
            sum+=n;
            if(n<min)
                min=n;
        }
    }
    if(min==101)
        printf("-1\n");
    else
        printf("%d\n%d\n",sum,min);
    return 0;
}

