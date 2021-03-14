#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool>mp;

bool solve(string a,string b)
{
    if(a.length()!=b.length())
        return false;
    if(a.compare(b)==0)    //if both strings are same
        return true;
    if(a.length() <= 1)     
        return false;

    int n=a.length();
    bool flag=false;

    string temp;                     //key - "a b"
    temp.append(a);
    temp.push_back(' ');
    temp.append(b);

    if(mp.find(temp)!=mp.end())
        return mp[temp];

    for(int i=1;i<=n-1;i++)
    {
        if( (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))
           || (solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i))) )
           {
               flag=true;
               break;
           }
    }
    return mp[temp]=flag;
}
int main()
{
    string a="great";
    string b="rgeat";
    bool ans=solve(a,b);
    cout<<ans;

   
}
