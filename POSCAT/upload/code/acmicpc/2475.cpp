#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    int n,i,sum=0;
 
    for(i=0;i<5;i++)
    {
        cin>>n;
        sum+=(n*n);
    }
 
    cout<<sum%10<<endl;
 
    return 0;
}

