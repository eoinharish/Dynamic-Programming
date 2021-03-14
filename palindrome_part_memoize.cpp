#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
bool isPalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j)
{   //base condition
    if(i>=j)                                //"","a" already palindrome
        return 0;
    if(isPalindrome(s,i,j))                //if string starting at index i and end at j is a palindrome,then we dont need to do any partition
        return 0;
    if(t[i][j] != -1)
        return t[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tempans = 1+solve(s,i,k)+solve(s,k+1,j);
        if(tempans<ans)
        {
            ans=tempans;
        }
    }
    return t[i][j]=ans;
}

int main()
{
    string s="nitik";
    memset(t,-1,sizeof(t));
    int final=solve(s,0,s.length()-1);
    cout<<final;
}