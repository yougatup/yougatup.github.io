#include <cstdio>
#include <iostream>
 
using namespace std;
 
int arr[100000];
 
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
    int n,i;
    int ggg,cnt=0;
 
    cin>>n;
 
    for(i=0;i<n;i++)
        cin>>arr[i];
 
    ggg=arr[1]-arr[0];
    for(i=1;i<n-1;i++)
        ggg=gcd(ggg,arr[i+1]-arr[i]);
 
    for(i=0;i<n-1;i++)
        cnt+=(arr[i+1]-arr[i])/ggg-1;
 
    cout<<cnt<<endl;
 
    return 0;
}

