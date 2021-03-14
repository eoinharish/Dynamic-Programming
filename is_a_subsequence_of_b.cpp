#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a="AXY";
    string b="ADXCPY";
    int n=a.length();
    int m=b.length();
    int t[n+1][m+1];

    //LCS
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
            else if(a[i-1]==b[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    if(t[n][m] == n){         //length of lcs == a.length()
        cout<<"true";
    }
    else
        cout<<"false";
    
}