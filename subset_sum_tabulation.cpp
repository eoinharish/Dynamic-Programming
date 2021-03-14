#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a[]={2,3,7,8};
    int sum=11;
    int n=4;

    bool t[n+1][sum+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=true;
            if(i==0)
                t[i][j]=false;
            
            if(a[i-1]<=j){
                t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    cout<<t[n][sum];

}