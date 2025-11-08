class Solution {
public:
    int longestPalindromeUsingRecursion(string& text1, string& text2, int i, int j) {
        if(i >= text1.length() || j >= text2.length()) return 0;
        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = 1 + longestPalindromeUsingRecursion(text1, text2, i+1, j+1);
        }
        else {
            ans = max(longestPalindromeUsingRecursion(text1, text2, i+1, j), longestPalindromeUsingRecursion(text1, text2, i, j+1));
        }
        return ans;
    }
    int longestPalindromeUsingDp(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if(i >= text1.length() || j >= text2.length()) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = 1 + longestPalindromeUsingDp(text1, text2, i+1, j+1, dp);
        }
        else {
            ans = max(longestPalindromeUsingDp(text1, text2, i+1, j, dp), longestPalindromeUsingDp(text1, text2, i, j+1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestPalindromeUsingTabulation(string& text1, string& text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        for(int i=text1.length()-1; i>=0; i--) {
            for(int j=text2.length()-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = 1 + dp[i+1][j+1];
                }
                else {
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;               
            }
        }
        return dp[0][0];
    }
    int longestPalindromeUsingSpaceOptimization(string& text1, string& text2) {
        vector<int> next(text2.length()+1, 0);
        vector<int> curr(text2.length()+1, 0);
        for(int i=text1.length()-1; i>=0; i--) {
            for(int j=text2.length()-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = 1 + next[j+1];
                }
                else {
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;               
            }
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        std::reverse(rev.begin(), rev.end());
        //int ans = longestPalindromeUsingRecursion(s, rev, 0, 0);
        //vector<vector<int>> dp(s.length()+1, vector<int>(rev.length()+1, -1));
        //int ans = longestPalindromeUsingDp(s, rev, 0, 0, dp);
        int ans = longestPalindromeUsingSpaceOptimization(s, rev);
        return ans;
    }
};