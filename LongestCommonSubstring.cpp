#include<bits/stdc++.h>
using namespace std;


int main()
{
    char x[]="abcdef";
    char y[]="abfdc";
    int n=strlen(x);
    int m=strlen(y);
    int t[n+1][m+1];
    int maxlength=0;

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {

            if(i==0 || j==0){
                t[i][j]=0;
            }
            else if(x[i-1]== y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
                maxlength=max(maxlength,t[i][j]);
                
            }
            else
                t[i][j]=0;  
        }                        
    }

     cout<<maxlength;


}