#include<bits/stdc++.h>
using namespace std;

//Time complexity -> O(n*m)    Space complexity-> extra table is required

//bottom up approach = Recursion + Memoization
int t[1001][1001];        //global declaration of table (matrix of (n+1)*(m+1)    ...constraints n,m<= 10^3

//length of longest common subsequence
int LCS(string s1,string s2,int n,int m)
{
    //BASE CONDITION
    if(n==0 || m==0)
    {
        return 0;
    }
    if(t[n][m] != -1)                     //if the value is already evaluated then return it from table. No need to compute it again
        return t[n][m];    
    //from the choice diagram
    if(s1[n-1]==s2[m-1])
        return t[n][m]=1+LCS(s1,s2,n-1,m-1);                      //store the values in tha table after computation
    else
        return t[n][m]=max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
     
}

int main()
{
    string x="abcd";
    string y="abd";
    int n=x.length();
    int m=y.length();

    memset(t,-1,sizeof(t));          //initialise the table with all -1's
    int res=LCS(x,y,n,m);

    cout<<res;
}
