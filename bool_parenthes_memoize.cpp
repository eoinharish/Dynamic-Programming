#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;        //we can also use table t[1001][1001][2]  as three variables are changing in the recursive calls
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
    //key for map is a string -> "i j isTrue"
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if(mp.find(temp)!=mp.end())  //key is already present in the map
    {
        return mp[temp];
    }
    int ans=0;
    //k loop scheme
    for(int k=i+1;k<=j-1;k+=2)     // k always point to the operator
    {
        int lt=solve(s,i,k-1,true);   //left expr as true
        int lf=solve(s,i,k-1,false);  //left expr as false
        int rt=solve(s,k+1,j,true);   //right expr as true
        int rf=solve(s,k+1,j,false);   //right expr as false

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
    return mp[temp]=ans;
}
int main()
{
    string s="T|T&F^T";
    int ways=solve(s,0,s.length()-1,true);
    cout<<ways;
}