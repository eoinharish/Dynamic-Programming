#include<bits/stdc++.h>
using namespace std;
//How to determine whether question is of type LCS
//1) In input, you are given two strings
//2) Question statement wants some optimised result(longest,shortest,min,max)(,i.e DP)
//Problem Statement:-> Minimum Number of Insertion and Deletion to convert String a to String b


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
    string a="heap";
    string b="pea";
    int n=a.length();
    int m=b.length();                         // heap to ea and then ea to pea
    int insertions,deletions;             //logic: first convert string a to LCS (deletions) and then LCS to string b (insertions)
    deletions=n-LCS(a,b,n,m);
    insertions=m-LCS(a,b,n,m);;
    cout<<"deletions: "<<deletions<<" insertions: "<<insertions;

}