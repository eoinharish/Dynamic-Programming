#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a="abcdef";
    string b="abegh";
    int n=a.length();
    int m=b.length();
    int t[n+1][m+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
            else if(a[i-1] == b[j-1])
            {
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    string ans="";
    
    int i=n;   //5
    int j=m;    //6
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans+=a[i-1];
            i--;j--;
        }
        else if(t[i-1][j] < t[i][j-1]){
                i=i;
                j=j-1;
        }
        else
        {
            i=i-1;
            j=j;
        }
        
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
