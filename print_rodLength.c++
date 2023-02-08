// OM SAI RAM //


/* QUESTION: 
Print Rod Lengths
Modify the bottom up dynamic programming code written to solve rod cutting problem  to print the size of the pieces that we should cut the rod to get maximum revenue 

Input Format

First line contains the length of the rod, n

Next line contains the length of each piece from 1 to n separated by a space

Output Format

Print length of rods and maximum revenue separated by a space

Example:

Input:

11

1 5 8 9 10 17 17 20 24 30 30

Output:

1 10 31   
*/


#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
int maximum(int a, int b)
{    
    if(a>b)
        return a;
    return b;
}
void print(vector<int> &s,int n){
    while(n>0){
        cout<<s[n]<<" ";
        n=n-s[n];
    }
}
int bottom_up_cut_rod(vector<int> &p, int length)
{    
    vector<int> r(100,0);
    vector<int> s(100,0);
    int i,q,j;
    r[0] = 0;
    for (j=1;j<=length;j++)
    {
        q = INT_MIN;
        for(i=1;i<=j;i++)
        {
            if(q<p[i-1]+r[j-i]){
                s[j]=i;
            }
            q = maximum(q,p[i-1]+r[j-i]);
        }
        r[j] = q;
    }
    print(s,length);
    return r[length];
}

int main()
{
    vector<int> p;
    int i,n,price,max_profit;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>price;
        p.push_back(price);
    }
    max_profit = bottom_up_cut_rod(p,n);
    cout<<max_profit;
}