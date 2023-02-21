/*Matrix Chain Multiplication Top Down
Develop a top down dynamic programming algorithm to find minimum cost for matrix chain multiplication. Print the tables maintained by the algorithm. For example, when there are six matrices and the input given is 

7
30 35 15 5 10 20 25

M table should be printed as 

15750 7875 9375 11875 15125 
2625 4375 7125 10500 
750 2500 5375 
1000 3500 
5000 
S table should be printed as 
1 1 3 3 3 
2 3 3 3 
3 3 3 
4 5 
5 
Input Format

First line contains the number of matrices +1, n

Next line contains the dimensions of the matrices in the chain

Output Format

Print the mtable

Print the s table

Print the minimum cost

Example:

Input:

7

30 35 15 5 10 20 25

Output:

15750 7875 9375 11875 15125

2625 4375 7125 10500

750 2500 5375

1000 3500

5000

1 1 3 3 3

2 3 3 3

3 3 3

4 5

5

15125*/


// OM SAI RAM //


#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
void matrix_chain_order(vector<int> p, vector<vector<int> >& m, vector<vector<int> >& s)
{
    //cout<<"entered"<<endl;
    int n,l,i,j,k,q;
    n = p.size()-1;
    // try length of chain from 2 to n
    for(l=2;l<=n;l++)
    {
        // From where does the chain starts is in 'i'
        //cout<<"l is "<<l<<endl;
        for(i=1;i<=n-l+1;i++)
        {
            // till what position does the chain goes is in 'j'
            j = i+l-1;
            //cout<<"i is "<<i<<" j is "<<j;
            m[i-1][j-1] = INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                //cout<< " k is "<<k<<endl;
                q = m[i-1][k-1] + m[k][j-1] + p[i-1]*p[k]*p[j];
                if(q<m[i-1][j-1])
                {
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
            }
        }
    }
}
void print_Optimal_Parens(vector<vector<int> >& s, int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_Optimal_Parens(s,i,s[i-1][j-1]);
        print_Optimal_Parens(s,s[i-1][j-1]+1,j);
        cout<<")";
    }
}
int main()
{    
    int n,i,j;
    cin>>n;
    vector<int> p(n);
    for(i=0;i<n;i++)
        cin>>p[i];
    vector<vector<int> > m(n-1,vector<int>(n-1,0));
    vector<vector<int> > s(n-1,vector<int>(n-1,0));
    matrix_chain_order(p,m,s);
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<m[0][n-2];

}