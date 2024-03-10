class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++) dp[i][0] = 1;
        for(int j = 0; j<n; j++) dp[0][j] = 1;
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int dr[2] = {1, 0};
    int dc[2] = {0, 1};
    int m, n;
    int INF = -1;
    vector<vector<int>> dp;
    int recurse(int i, int j){ // i, j부터 m-1, n-1까지 경우의 수
        if(i == m -1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != INF) return dp[i][j];
    
        int cnt = 0;
        for(int d = 0; d<2; d++){
            int br = i + dr[d];
            int bc = j + dc[d];
            if(0 <= br && br < m && 0 <= bc && bc < n){
                cnt += recurse(br, bc);
            }
        }
        dp[i][j] = cnt;
        return cnt;
    }
    int uniquePaths(int _m, int _n) {
        m = _m; n = _n;
        vector<vector<int>> _dp(m, vector<int>(n, INF)); dp = _dp;

        return recurse(0, 0);
    }
};