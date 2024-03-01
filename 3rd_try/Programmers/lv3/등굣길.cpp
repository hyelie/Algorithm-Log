#include <string>
#include <iostream>
#include <vector>

using namespace std;

int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    // 초기 정보
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(vector<int> puddle : puddles){
        dp[puddle[0]][puddle[1]] = -1;
    }
    
    // 초기값
    for(int i = 1; i<=m; i++){
        if(dp[i][1] == -1) break;
        dp[i][1] = 1;
    }
    for(int j = 1; j<=n; j++){
        if(dp[1][j] == -1) break;
        dp[1][j] = 1;
    }
    
    // dp
    for(int i = 2; i<=m; i++){
        for(int j = 2; j<=n; j++){
            if(dp[i][j] == -1) continue;
            
            int top = dp[i-1][j];
            if(top == -1) top = 0;
            
            int left = dp[i][j-1];
            if(left == -1) left = 0;
            
            dp[i][j] = (top + left) % MOD;
        }
    }
    
    return dp[m][n];
}