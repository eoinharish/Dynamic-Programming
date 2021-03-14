#include<bits/stdc++.h>
using namespace std;
//Problem Statement:- Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position,
//  i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.


int main()
{
    string a="AABEBCDD";    //given
    string b=a;            //we are making another same string
    int n=a.length();
    int m=b.length();
    int t[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
            else if(a[i-1]==b[j-1] && i!=j)        //if both char are same but not at the same index then include it
                t[i][j]=1+t[i-1][j-1];
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    cout<<t[n][m];            //output->3 (ABD)
}