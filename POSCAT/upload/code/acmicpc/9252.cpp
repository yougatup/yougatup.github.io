#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
 
using namespace std;
 
int d[1000][1000];
int dir[1000][1000];
stack<char> st;
 
int main()
{
    string a,b;
    int i,j,la,lb;
 
    cin>>a>>b;
 
    if(a[0]==b[0])
        d[0][0]=1;
    for(i=1,la=a.size();i<la;i++)
    {
        if(a[i]==b[0])
		{
            d[i][0]=1;
			dir[i][0]=3;
		}
        else
		{
            d[i][0]=d[i-1][0];
        	dir[i][0]=2;
		}
    }
    for(j=1,lb=b.size();j<lb;j++)
    {
        if(a[0]==b[j])
		{
            d[0][j]=1;
			dir[0][j]=3;
		}
        else
		{
            d[0][j]=d[0][j-1];
        	dir[0][j]=1;
		}
    }
 
    for(i=1;i<la;i++)
        for(j=1;j<lb;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
                dir[i][j]=3;
            }
 
            if(d[i][j]<d[i-1][j])
            {
                d[i][j]=d[i-1][j];
                dir[i][j]=2;
            }
 
            if(d[i][j]<d[i][j-1])
            {
                d[i][j]=d[i][j-1];
                dir[i][j]=1;
            }
        }
 
    cout<<d[la-1][lb-1]<<endl;
 
    i=la-1;
    j=lb-1;
 
    while(i>=0 && j>=0)
    {
        if(a[i]==b[j])
            st.push(a[i]);
		if(i==0 && j==0)
			break;
        if(dir[i][j]==3)
        {
            i--;
            j--;
        }
        else if(dir[i][j]==2)
            i--;
        else
            j--;
    }
 
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
 
    return 0;
}

