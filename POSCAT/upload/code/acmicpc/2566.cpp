#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    int i,j;
    int n;
    int m,mi,mj;
 
    m=-1;
     
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            cin>>n;
            if(m<n)
            {
                m=n;
                mi=i;
                mj=j;
            }
        }
    }
 
    printf("%d\n%d %d\n",m,mi,mj);
 
    return 0;
}

