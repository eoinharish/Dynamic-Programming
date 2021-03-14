#include<bits/stdc++.h>
using namespace std;

//Problem Statement: Minimum number of deletion in a string to make it a palindrome
//Hint: Minimun deletions occur when we found the longest palindrome.
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
    int deletions;
    string b="";       
    for(int i=a.length()-1;i>=0;i--)
    {
        b.push_back(a[i]);
    }
    int lps=LCS(a,b,a.length(),b.length());               //lps = LCS(a,reverse(a))
    deletions= a.length()-lps;





    cout<<deletions;

}
//Important conclusion:-> no of deletions and no of insertions are same to make a string palindrome. therefore,
//if we are required to find the min no. of insertions in a string to make it a palindrome ans would be same,i.e,
// s.length()-lps