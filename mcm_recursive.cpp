#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int j)
{ 
    //base condition
    if(i>=j) 
        return 0;   
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(tempans<min)
        {
            min=tempans;
        }

    } 
    return min;
}

int main()
{
    int arr[]={5,4,6,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    int final=solve(arr,1,n-1);
    cout<<final;

}