class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        // dp[i][j] : index i to j까지 max palindrome subsequence length
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++) dp[i][i] = 1;

        for(int d = 1; d<n; d++){
            for(int i = 0; i<n-d; i++){
                int j = i+d;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j-1]));                
            }
        }

        return n - dp[0][n-1];
    }
};

class Solution {
public:
    int recurse(vector<vector<int>> &dp, string &s, int i, int j){
        if(dp[i][j] != 0) return dp[i][j];
        if(i == j) return 1;
        if(i > j) return 0;
        if(s[i] == s[j]){
            dp[i][j] = recurse(dp, s, i+1, j-1) + 2;
            return dp[i][j];
        }
        else{
            dp[i][j] = max(recurse(dp, s, i+1, j), recurse(dp, s, i, j-1));
            return dp[i][j];
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        // dp[i][j] : index i to j까지 max palindrome subsequence length
        vector<vector<int>> dp(n, vector<int>(n, 0));

        return n - recurse(dp, s, 0, n-1);
    }
};