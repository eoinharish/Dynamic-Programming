#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int sum,int n)
{
    int t[n+1][sum+1];
    
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=0;
            else if(i==0)
                t[i][j]=INT_MAX;
            else if(a[i-1]<=j){
                t[i][j]=min(1+t[i][j-a[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    if(t[n][sum]==INT_MAX)
        return -1;
    return t[n][sum];
}
int main()
{
    int a[]={2,1};
    int n=2;
    int sum=7;

    int ans=solve(a,sum,n);
    cout<<ans;
}