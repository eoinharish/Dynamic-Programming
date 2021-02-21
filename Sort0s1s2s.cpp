#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a[]={0,1,0,1,1,2,0,1,2,1,0,0};         //0's ->5,  1's->5  , 2's->2

    int n = sizeof(a)/sizeof(a[0]);
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        switch(a[mid])
        {
            //If the element is 0
            case 0: swap(a[low],a[mid]);
                    low++; mid++;
                    break;

            //If the element is 1        
            case 1: mid++;
                    break;

            //If the element is 2
            case 2: swap(a[high],a[mid]);
                    high--;
                    break;
        }
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}



// [0...low-1]  -> 0
// [high+1...n] -> 2