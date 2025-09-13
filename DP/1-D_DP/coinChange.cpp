#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solveByRecursion(vector<int>& coins, int n, int amount) {
    // Base case
    if(amount == 0) {
        return 0;
    }
    if(amount < 0) {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int ans = solveByRecursion(coins, n, amount-coins[i]);
        if(ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int topDownApproach(vector<int>& coins, int n, int amount, vector<int>& dp) {
    if(amount == 0) {
        return 0;
    }
    if(amount < 0) {
        return INT_MAX;
    }
    if(dp[amount] != -1) {
        return dp[amount];
    }
    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int ans = topDownApproach(coins, n, amount-coins[i], dp);
        if(ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    dp[amount] = mini;
    return mini;
}
int bottomUpApproach(vector<int>& coins, int n, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int target=1; target<=amount; target++) {
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
                if(target-coins[i] >= 0) {
                int ans = dp[target-coins[i]];
                if(ans != INT_MAX) {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        dp[target] = mini; 
    }
    return dp[amount];
}
int coinChange(vector<int>& coins, int n, int amount) {
    // int ans = solveByRecursion(coins, n, amount);
    // cout << "Answer is: " << ans;

    // vector<int> dp(amount+1, -1);
    // int ans = topDownApproach(coins, n, amount, dp);
    // if(ans == INT_MAX) {
    //     cout << -1 << endl;
    // }
    // else cout << "Answer is: " << ans;

    int ans = bottomUpApproach(coins, n, amount);
    cout << "Answer is: " << ans;

    // No Space Optimization is possible because dp[i] is depend upon dp[i - coins[j]]
}
int main() {
    vector<int> coins = {1,2,5};
    int n = coins.size();
    int amount = 11;
    coinChange(coins, n, amount);
}