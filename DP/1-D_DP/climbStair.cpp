#include<iostream>
#include<vector>
using namespace std;
    int solveByRecursion(int n) {
        if(n < 0) return 0;
        if(n == 0 || n == 1) return 1;
        int ans = solveByRecursion(n-1) + solveByRecursion(n-2);
        return ans; 
    }
    int topDownApproach(int n, vector<int>& dp) {
        if(n < 0) return 0;
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = topDownApproach(n-1, dp) + topDownApproach(n-2, dp);
        return dp[n];  
    }
    int bottomUpApproach(int n) {
        if(n < 0) return 0;
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int spaceOptimization(int n) {
        if(n < 0) return 0;
        int prev2 = 1;
        int prev1 = 1;
        int curr = 0;
        if(n == 0) return prev2;
        if(n == 1) return prev1;
        for(int i=2; i<=n; i++) {
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int climbStairs(int n) {
        // int ans = solveByRecursion(n);
        // return ans;

        // vector<int>dp(n+1, -1);
        // int ans = topDownApproach(n, dp);
        // return ans;

        // int ans = bottomUpApproach(n);
        // return ans;

        int ans = spaceOptimization(n);
        return ans;
}
int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    climbStairs(n);
}