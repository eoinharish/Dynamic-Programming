#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int solve(int a[],int sum,int n)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;

    if(t[n][sum]!=-1)
        return t[n][sum];
    if(a[n-1]<=sum)
    {
        return t[n][sum]=solve(a,sum-a[n-1],n-1) + solve(a,sum,n-1);      // "||"" ki jgh "+"" aa jaega 
    }
    else{
        return t[n][sum]=solve(a,sum,n-1);
    }

}
int main()
{
    int a[]={2,3,5,6,8,10};
    int sum=10;
    memset(t,-1,sizeof(t));

    int ans=solve(a,sum,6);

    cout<<ans;

}