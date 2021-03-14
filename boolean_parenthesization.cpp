#include<bits/stdc++.h>
using namespace std;

// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
int solve(string s,int i,int j,bool isTrue)
{
    //Base condition
    if(i>j)                  //if no elements
        return 0;
    if(i==j){                //if i and j points to same element(single element is there)
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
        
    }
    int ans=0;
    //k loop scheme
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lt=solve(s,i,k-1,true);   //no of ways
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);

        if(s[k]=='&')
        {
            if(isTrue==true)
                ans+=lt*rt;
            else
                ans+=lf*rt+lt*rf+lf*rf;
            
        }
        else if(s[k]=='|')
        {
            if(isTrue==true)
                ans+=lt*rf+lf*rt+lt*rt;
            else
                ans+=lf*rf;
        }
        else if(s[k]=='^')
        {
            if(isTrue==true)
                ans+=lt*rf+lf*rt;
            else
                ans+=lt*rt+lf*rf;
            
        }
        

    }
    return ans;
}
int main()
{
    string s="T&F|F^T";
    int ways=solve(s,0,s.length()-1,true);
    cout<<ways;
}