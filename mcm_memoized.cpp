#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

int solve(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    if(t[i][j] != -1)
    {
        return t[i][j];
    }
    int min=INT_MAX;

    for(int k=i;k<=j-1;k++)
    {
        int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(tempans<min)
        {
            min=tempans;
        }
    }
    return t[i][j]=min;
}

int main()
{
    int arr[]={10, 20, 30, 40, 30};
    int n=sizeof(arr)/sizeof(arr[0]);

    memset(t,-1,sizeof(t));
    int final=solve(arr,1,n-1);
    cout<<final;

}