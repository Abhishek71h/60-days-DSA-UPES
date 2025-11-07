#include<iostream>
#include<vector>
using namespace std;

int longestCommonSubsequenceUsingRecursion(string& str1, string& str2, int i, int j) {
    // Base Case -> T.C. = O(2^(n+m)), S.C. = O(n + m)
    if(i >= str1.length() || j >= str2.length()) return 0;
    int ans = 0;
    if(str1[i] == str2[j]) {
        ans = 1 + longestCommonSubsequenceUsingRecursion(str1, str2, i+1, j+1);
    }
    else {
        ans = max(longestCommonSubsequenceUsingRecursion(str1, str2, i+1, j), longestCommonSubsequenceUsingRecursion(str1, str2, i, j+1));
    }
    return ans;
}

int longestCommonSubsequenceUsingDp(string& str1, string& str2, int i, int j, vector<vector<int>>& dp) {
    // Base case -> T.C. = O(n * m), O(n * m)
    if(i >= str1.length() || j >= str2.length()) return 0;
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if(str1[i] == str2[j]) {
        ans = 1 + longestCommonSubsequenceUsingDp(str1, str2, i+1, j+1, dp);
    }
    else {
        ans = max(longestCommonSubsequenceUsingDp(str1, str2, i+1, j, dp), longestCommonSubsequenceUsingDp(str1, str2, i, j+1, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int longestCommonSubsequenceUsingTabulation(string& str1, string& str2) {
    // T.C = O(n * m), S.C. = O(n * m)
    vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, 0));
    for(int i=str1.length()-1; i>=0; i--) {
        for(int j=str2.length()-1; j>=0; j--) {
            int ans = 0;
            if(str1[i] == str2[j]) {
                ans = 1 + dp[i+1][j+1];
            }
            else {
                ans = max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int longestCommonSubsequenceUsingSpaceOptimization(string& str1, string& str2) {
    // T.C. = O(n * m), O(m)
    vector<int> curr(str2.length()+1, 0);
    vector<int> next(str2.length()+1, 0);
    for(int i=str1.length()-1; i>=0; i--) {
        for(int j=str2.length()-1; j>=0; j--) {
            int ans = 0;
            if(str1[i] == str2[j]) {
                ans = 1 + next[j+1];
            }
            else {
                ans = max(next[j],curr[j+1]);
            }
            curr[j] = ans;
        }
        // shift
        next = curr;
    }
    return next[0];   
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    int i = 0;
    int j = 0;
    // int ans = longestCommonSubsequenceUsingRecursion(text1, text2, i, j);
    //vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
    int ans = longestCommonSubsequenceUsingSpaceOptimization(text1, text2);
    cout << "Answer is: " << ans;
    return 0;
}