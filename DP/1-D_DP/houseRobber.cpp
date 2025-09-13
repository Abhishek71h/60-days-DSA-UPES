#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solveByRecursion(vector<int>& nums, int n) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return nums[0];
    }
    int include = solveByRecursion(nums, n-2) + nums[n];
    int exclude = solveByRecursion(nums, n-1);
    int ans = max(include, exclude);
    return ans;
}
int topDownApproach(vector<int>& nums, int n, vector<int>& dp) { 
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return nums[0];
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int include = topDownApproach(nums, n-2, dp) + nums[n];
    int exclude = topDownApproach(nums, n-1, dp);
    dp[n] = max(include, exclude);
    return dp[n];
}
int bottomUpApproach(vector<int>& nums, int n) {
    vector<int> dp(n+1, INT_MIN);
    dp[0] = nums[0];
    for(int i=1; i<=n; i++) {
        int temp = 0;
        if(i-2 >= 0) {
            temp = dp[i-2];
        }
        int include = temp + nums[i];
        int exclude = dp[i-1];
        dp[i] = max(include, exclude);
    }
    return dp[n];  
}
int spaceOptimization(vector<int>& nums, int n) {
    int prev2 = 0;
    int prev1 = nums[0];
    int curr;
    for(int i=1; i<=n; i++) {
        int temp = 0;
        if(i-2 >= 0) {
            temp = prev2;
        }
        int include = temp + nums[i];
        int exclude = prev1;
        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main() {
    vector<int> nums = {1,2,3,1};
    int n = nums.size()-1;
    // int ans = solveByRecursion(nums, n);
    // cout << "Answer is: " << ans << endl;
    // vector<int> dp(n+1, -1);
    // int ans = topDownApproach(nums, n, dp);
    // cout << "Answer is: " << ans << endl;

    // int ans = bottomUpApproach(nums, n);
    // cout << "Answer is: " << ans << endl;

    int ans = spaceOptimization(nums, n);
    cout << "Answer is: " << ans << endl;
}