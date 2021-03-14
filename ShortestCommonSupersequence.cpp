#include<bits/stdc++.h>
using namespace std;
//Sequence-> order must not be changed but discontinuity can be there between characters.
//Problem Statement: Find the length of shortest common supersequence.
//shortest common supersequence is the shortest possible string which contains both the given strings

int t[1001][1001];
int LCS(string a,string b,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                t[i][j]= 1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];
}

int main()
{
    string a="AGGTAB";
    string b="GXTXAYB";
    int n=a.length();
    int m=b.length();
    int ans;
    ans=(n+m)-LCS(a,b,n,m);             //worst case length of common supersequence-> n+m
    cout<<ans;
}