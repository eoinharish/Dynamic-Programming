#include<bits/stdc++.h>
using namespace std;

// Naive recursive solution. Time complexity -> O(2^n)     Space complexity -> max depth of the stack
//length of longest common subsequence
int LCS(string s1,string s2,int n,int m)
{
    //BASE CONDITION
    if(n==0 || m==0)
    {
        return 0;
    }

    //from the choice diagram
    if(s1[n-1]==s2[m-1])
        return 1+LCS(s1,s2,n-1,m-1);
    else
        return max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
     
}

int main()
{
    string x="abcd";
    string y="ef";
    int n=x.length();
    int m=y.length();
    int res=LCS(x,y,n,m);

    cout<<res;

}