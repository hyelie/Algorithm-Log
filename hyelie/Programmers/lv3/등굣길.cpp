// 7분에 다 풀었고, 효율성에서 다 틀림.
// MOD 연산을 안 했다! 엄...

#include <string>
#include <vector>
#include <set>

using namespace std;

/*
세로 m, 가로 n 길찾기 DP
점화식
i, j의 경우의 수 = i-1, j 경우의 수 + i, j-1 경우의 수
*/

typedef pair<int, int> pii;
int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    set<pii> puddle_set;
    for(vector<int> puddle : puddles){
        puddle_set.insert({puddle[0]-1, puddle[1]-1});
    }
    
    // init
    for(int r = 0; r<m; r++){
        if(puddle_set.find({r, 0}) != puddle_set.end()) break;
        dp[r][0] = 1;
    }
    for(int c = 0; c<n; c++){
        if(puddle_set.find({0, c}) != puddle_set.end()) break;
        dp[0][c] = 1;
    }
    
    // dp
    for(int r = 1; r<m; r++){
        for(int c = 1; c<n; c++){
            if(puddle_set.find({r, c}) != puddle_set.end()) continue;
            dp[r][c] = (dp[r-1][c] % MOD + dp[r][c-1] % MOD) % MOD;
        }
    }
    
    return dp[m-1][n-1];
}