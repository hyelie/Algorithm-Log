// Runtime 332 ms Beats 47.42%
// Memory 79.1 MB Beats 31.90%

typedef long long ll;

class Solution {
public:
    int MOD = 1e9 + 7, T, W, S;
    int numWays(vector<string>& words, string target) {
        T = target.size(), W = words.size(), S = words[0].size();
        vector<vector<int>> cnt(S, vector<int>(26, 0)); // cnt[i] : 모든 words들의 ith index의 char 개수
        for(int i = 0; i<W; i++){
            for(int j = 0; j<S; j++){
                cnt[j][words[i][j] - 'a']++;
            }
        }

        vector<vector<ll>> dp(S+1, vector<ll>(T+1));
        // dp[i][j] : substring j까지 ith col 이용해 만드는 경우의 수
        // ith col에 있는 char 사용하는 경우 dp[i][j] * ith col의 target[j] 개수
        // ith col에 있는 char 사용하지 않는 경우 dp[i][j+1]

        for(int i = 0; i<S; i++){
            dp[i][0] = 1;
            for(int j = 0; j<T; j++){
                dp[i + 1][j + 1] = ((cnt[i][target[j] - 'a'] * dp[i][j]) % MOD + dp[i][j + 1]) % MOD;
            }
        }

        return dp[S][T];
    }
};