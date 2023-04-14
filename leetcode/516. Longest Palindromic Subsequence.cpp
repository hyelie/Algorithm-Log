// Runtime 124 ms Beats 69.24%
// Memory 73 MB Beats 36.29%

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        // initialize
        for(int i = 0; i<len; i++) dp[i][i] = 1;
        
        // dp
        for(int d = 1; d<len; d++){
            for(int i = 0; i<len - d; i++){
                int j = i + d;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][len-1];
    }
};