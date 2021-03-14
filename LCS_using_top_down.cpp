#include<bits/stdc++.h>
using namespace std;

//Top down -> using only table. Recursion is avoided as it uses stack and stack memory has some limit.
//Therefore to avoid stack overflow, we use top down DP.

// int LCS(string s1,string s2,int n,int m)
// {
//     //BASE CONDITION
//     if(n==0 || m==0)
//     {
//         return 0;
//     }

//     //from the choice diagram
//     if(s1[n-1]==s2[m-1])
//         return 1+LCS(s1,s2,n-1,m-1);
//     else
//         return max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
     
// }

int main()
{
    string s1="abcd";
    string s2="abd";
    int n=s1.length();
    int m=s2.length();
    int t[n+1][m+1];
    //Initialising first row and first column of table with 0 (using base condition of recursion)
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    //Filling up other values in the table
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    cout<<t[n][m];


}