#include<iostream>
#include<vector>
using namespace std;
int solveByRecursion(int n) {
    // Base Case
    if(n == 1 || n == 0) {
        return n;
    }
    int ans = solveByRecursion(n-1) + solveByRecursion(n-2);
    return ans;
}
int topDownApproach(int n, vector<int>& dp) {
    if(n == 1 || n == 0) {
        return n;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = topDownApproach(n-1, dp) + topDownApproach(n-2, dp);
    return dp[n];
}
int bottomUpApproach(int n) {
    // Step1: Create dp array
    vector<int>dp(n+1, -1);

    // Step2: Observe base case
    dp[0] = 0;
    if(n == 0) {
        return dp[0];
    }
    dp[1] = 1;
    if(n == 1) {
        return dp[1];
    }

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int spaceOptimization(int n) {
    int prev2 = 0;
    int prev1 = 1;
    if(n == 0) {
        return prev2;
    }
    if(n == 1) {
        return prev1;
    }
    int curr;
    for(int i=2; i<=n; i++) {
        curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int fib(int n) {
    // int ans = solveByRecursion(n);
    // cout << "Answer is: "<< ans;

    // For Top-Down Approach
    // Step 1: Create a dp Array
    // vector<int>dp(n+1, -1);
    // int ans = topDownApproach(n, dp);
    // cout << "Answer is: "<< ans;

    // For Bottom-Up Approach
    // int ans = bottomUpApproach(n);
    // cout << "Answer is: "<< ans;

    // Space Optimization
    int ans = spaceOptimization(n);
    cout << "Answer is: "<< ans;
}
int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    fib(n);
}