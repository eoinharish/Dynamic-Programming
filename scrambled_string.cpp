#include<bits/stdc++.h>
using namespace std;

bool solve(string a,string b)
{
   
    if(a.compare(b)==0)                      //if both strings are same
        return true;
    if(a.length()<=1)                       //eg a="a"    b="b"
        return false;

    int n=a.length();
    bool flag=false;

    for(int i=1;i<=n-1;i++)              //break at each i
    {
        if( (solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)) )
            || (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i))) )
        {    
            flag=true;
            break;
        }
    }
    return flag;
}

int main()
{
    string a="great";
    string b="rgeat";
    bool ans;
    if(a.length()!=b.length())
        ans=false;
        
    if(a.length()==0 && b.length()==0)     //if both str are empty
        ans=true;

    ans=solve(a,b);
    cout<<ans;


}