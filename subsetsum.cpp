#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int solve(int a[],int sum,int n)
{
    if(sum==0)
        return true;
    if(n==0)
        return false;

    if(t[n][sum]!=-1)
        return t[n][sum];
    else{
    if(a[n-1]<=sum)
    {
        return t[n][sum]=solve(a,sum-a[n-1],n-1) || solve(a,sum,n-1);
    }
    else{
        return t[n][sum]=solve(a,sum,n-1);
    }
    }
}
int main()
{
    int a[]={2,3,7,8};
    int sum=1;
    memset(t,-1,sizeof(t));

    int ans=solve(a,sum,4);

    cout<<ans;

}