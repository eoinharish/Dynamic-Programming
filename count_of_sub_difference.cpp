#include<bits/stdc++.h>
using namespace std;

int subsetsum(int a[],int sum,int n)
{
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=1;
            else if(i==0)
                t[i][j]=0;
            else if(a[i-1]<=j)
                t[i][j]= t[i-1][j-a[i-1]] + t[i-1][j];
            else
            {
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    return t[n][sum];
}

int main()
{
    int a[]={1,1,2,3};
    int d=1;
    int n=4;

    int range=0;
    for(int i=0;i<n;i++)
    {
        range+=a[i];
    }
    int s1=(range+d)/2;

    cout<<subsetsum(a,s1,n)<<endl;    //ANS


}