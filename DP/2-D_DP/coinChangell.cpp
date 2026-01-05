/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.The answer is guaranteed to fit into a signed 32-bit integer.

Example: 
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

#include<iostream>
#include<vector>
using namespace std;
int solveUsingRecursion(vector<int>& coins, int amount, int n, int index) {
    // base case
    if(index >= n) {
        return 0;
    }
    if(amount == 0) {
        return 1;
    }
    int ways = 0;
    if(amount >= coins[index]) {
        ways += solveUsingRecursion(coins, amount-coins[index], n, index);
    }
    ways += solveUsingRecursion(coins, amount, n, index+1);
    return ways;
}
int solveUsingTopDown(vector<int>& coins, int amount, int n, int index, vector<vector<int>>& dp) {
    // base case
    if(index >= n) {
        return 0;
    }
    if(amount == 0) {
        return 1;
    }
    if(dp[index][amount] != -1) {
        return dp[index][amount];
    }
    int ways = 0;
    if(amount >= coins[index]) {
        ways += solveUsingTopDown(coins, amount-coins[index], n, index, dp);
    }
    ways += solveUsingTopDown(coins, amount, n, index+1, dp);
    dp[index][amount] = ways;
    return dp[index][amount];
}
int main() {
    vector<int> coins = {1,2,5};
    int amount = 5;
    int n = coins.size();
    int index = 0;
    // int ans = solveUsingRecursion(coins, amount, n, index);
    vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    int ans = solveUsingTopDown(coins, amount, n, index, dp);
    cout << "Answer is: " << ans << endl;
    return 0;
}