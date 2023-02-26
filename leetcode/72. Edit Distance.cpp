// Runtime 7ms Beats 92.32%
// Memory 8.9MB Beats 63.20%

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

        // init
        for(int i = 0; i<=len1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= len2; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i<=len1; i++){
            for(int j = 1; j<=len2; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);
            }
        }

        return dp[len1][len2];
    }
};

/*
dp[i][j] : word1[0...i]을 word2[0...j]로 바꾸는 데 min값

이 부분은, 같은 게 있으면 len-1이고 없으면 len임
word1[i] == word2[j]면 dp[i][j] = dp[i-1][j-1] (안바꿔도 됨)
else면 그걸 바꿔야 하니까 dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1
*/