#include<bits/stdc++.h>
using namespace std;

//Given a sequence, find the length of the longest palindromic subsequence in it
//How to match it with LCS?
//I/P format, question, O/P format
//question is almost same(longest,subsequence), O/P format is same(int) but I/P format are not same
//Lets try to find some another string which can be derived from string a so that we can get two input strings and hence matching the question with LCS type.
//Lets consider another string b which is the reverse of string a and try to solve the problem.
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
    string a="aman";
    string b="";       
    for(int i=a.length()-1;i>=0;i--)
    {
        b.push_back(a[i]);
    }
    cout<<b;
    int ans=LCS(a,b,a.length(),b.length());
    cout<<ans;

}
//VERY IMP
//CONCLUSION: LPS(string a) = LCS(a,reverse(a))