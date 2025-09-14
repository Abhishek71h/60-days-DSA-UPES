/*Question: There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
Constraint: n and k are non-negative integers.
Eg: Given n=4, k=3 return 66
*/

#include<iostream>
#include<vector>
using namespace std;
int solveByRecursion(int n, int k) {
    // Base Case
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return (k + k*(k-1)); //k*k
    }
    int ans = (solveByRecursion(n-2, k) + solveByRecursion(n-1, k)) * (k-1);
    return ans;
}
int topDownApproach(int n, int k, vector<int>& dp) {
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return (k + k*(k-1)); //k*k
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = (topDownApproach(n-2, k, dp) + topDownApproach(n-1, k, dp)) * (k-1);
    return dp[n];
}
int bottomUpApporoch(int n, int k) {
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = (k + k*(k-1));
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-2] + dp[i-1]) * (k-1); 
    }
    return dp[n];
}
int spaceOptimization(int n, int k) {
    int prev2 = k;
    int prev1 = (k + k*(k-1));
    for(int i=3; i<=n; i++) {
        int curr = (prev2 + prev1) * (k-1); 
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main() {
    int n = 4; // No of fence
    int k = 3; // No of colour
    // int ans = solveByRecursion(n, k);
    // cout << "Answer is: " << ans;
    // vector<int> dp(n+1, -1);
    // int ans = topDownApproach(n, k, dp);
    // cout << "Answer is: " << ans;

    // int ans = bottomUpApporoch(n, k);
    // cout << "Answer is: " << ans;

    int ans = spaceOptimization(n, k);
    cout << "Answer is: " << ans;
    return 0;
}