/*Question: Given a non-negative integer n, your task is to find the nth Fibonacci number.
The Fibonacci sequence is a sequence where the next term is the sum of the previous two terms. The first two terms of the Fibonacci sequence are 0 followed by 1. The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21
The Fibonacci sequence is defined as follows:

F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) for n > 1

Examples :

Input: n = 5
Output: 5
Explanation: The 5th Fibonacci number is 5.

Input: n = 0
Output: 0 
Explanation: The 0th Fibonacci number is 0.

Input: n = 1
Output: 1
Explanation: The 1st Fibonacci number is 1.

Constraints:
0 ≤ n ≤ 30

Solution:
*/
class Solution {
  public:
    /*int solveByRecursion(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        int result = solveByRecursion(n-1) + solveByRecursion(n-2);
        return result;
    }
    */
    int solveByDp(int n,vector<int>& dp) {
        if(n == 0 || n == 1) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solveByDp(n-1, dp) + solveByDp(n-2, dp);
        return dp[n];
    }
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1, -1);
        //int ans = solveByRecursion(n);
        int ans = solveByDp(n,dp);
        return ans;
    }
};