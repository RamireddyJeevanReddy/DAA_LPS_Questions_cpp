// OM SAI RAM //

/* Q: Cut into lengths 3 or 5

A variation of rod cutting problem is one in which length of the rod will be of length greater than or equal to 8 and you can make cuts of rods of length 3 or 5 only. For each unit of wastage a penalty of Rs.1 should be given. Write an recursive algorithm and implement it to find the maximum  revenue that may be generated.

Input Format

First line contains the length of the rod,n

Next line contains the price of rod of length 3 and 5 separated by a space

Output Format

Print the maximum revenue that may be generated

 

Example:

Input:

3

1 5

Output:

1
*/

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
int ans=0;
int maximum(int a, int b)
{    
    if(a>b)
        return a;
    return b;
}

int memoized_cut_rod_aux(int price_1,int price_2,int n)
{
    if(n<3){
        for(int i=0;i<n;i++){
            ans=ans-1;
        }
    }
    else if(n-5>=0){
        ans=ans+price_2;
        memoized_cut_rod_aux(price_1,price_2,n-5);
    }
    else if(n-3>=0){
        ans=ans+price_1;
        memoized_cut_rod_aux(price_1,price_2,n-3);
    }
    return ans;
}
int main()
{
    int n,price_1,price_2,max_profit;
    
    cin>>n;
    cin>>price_1;
    cin>>price_2;
    max_profit = memoized_cut_rod_aux(price_1,price_2,n);
    cout<<max_profit;
}