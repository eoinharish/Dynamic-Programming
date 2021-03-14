#include<bits/stdc++.h>
using namespace std;



int main()
{
    string a="ab";
    string b="abc";
    int n=a.length();
    int m=b.length();
    int t[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
            else if(a[i-1]==b[j-1]){
                t[i][j]= 1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    int i=n;
    int j=m;
    string ans="";

    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1])
            {
                ans.push_back(a[i-1]);
                i--;
            }
            else{
                ans.push_back(b[j-1]);
                j--;
            }
        }
    }
    //copying the remaining items if any
    while(i>0)
    {
        ans.push_back(a[i-1]);
        i--;
    }
    while(j>0)
    {
        ans.push_back(b[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;

}