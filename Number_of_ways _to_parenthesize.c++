// OM SAI RAM //



/*Number of ways to parenthesize
In matrix chain multiplication problem, given the number of matrices to be multiplied, write a C++ program to find the number of ways it may be parenthesized. For example, when there are three matrices A1, A2 and A3 there are two ways to parenthesize them. (A1(A2A3)) and ((A1A2)A3). If there are four matrices A1, A2, A3 and A4 then there are five ways to parenthesize as shown (A1(A2(A3A4))), (A1((A2A3)A4)), ((A1,A2)(A3A4)), ((A1(A2A3))A4), (((A1A2)A3)A4).

Input Format

First line contains the number of matrices in the chain, n

Output Format

Print the possible number of parenthesization.

 

Example:

Input:

4

Output:

5*/


#include <iostream>
using namespace std;

int countParenthesis(int n) {
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = 1;
            } else {
                for (int k = i; k <= j - 1; k++) {
                    dp[i][j] += dp[i][k] * dp[k + 1][j];
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    int n;
    cin >> n;
    cout << countParenthesis(n);
    return 0;
}