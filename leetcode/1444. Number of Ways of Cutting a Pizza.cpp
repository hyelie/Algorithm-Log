// Runtime 13 ms Beats 91.88%
// Memory 7.5 MB Beats 94.50%

typedef long long ll;

ll MOD = 1e9 + 7;

int psum[51][51];
int dp[51][51][11];

class Solution {
public:
    int maxr, maxc;
    int DFS(int r, int c, int k){
        if(psum[r][c] == 0) return 0;
        if(k == 0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];

        ll cnt = 0;

        // row를 자를 수 있는지 판단. 마지막 col만 보면 됨
        // 마지막 col이 모든 row방향이 합쳐져 있음. 
        for(int i = r+1; i<maxr; i++){
            if(psum[r][c] - psum[i][c] > 0){
                cnt = (cnt + DFS(i, c, k-1)) % MOD;
            }
        }

        // col을 자를 수 있는지 판단. 마지막 row만 보면 됨.
        for(int j = c+1; j<maxc; j++){
            if(psum[r][c] - psum[r][j] > 0){
                cnt = (cnt + DFS(r, j, k-1)) % MOD;
            }
        }

        dp[r][c][k] = cnt;
        return cnt;
    }
    int ways(vector<string>& pizza, int k) {
        // dp 초기화
        maxr = pizza.size(); maxc = pizza[0].size();
        for(int i = 0; i<maxr; i++){
            for(int j = 0; j<maxc; j++){
                for(int m = 0; m<k; m++){
                    dp[i][j][m] = -1;
                }
            }
        }

        // trick : [0, 0]부터 [m, n]까지 하면 왼쪽 위에서 자른 결과가 후에 반영되지 않음.
        // 따라서 [m, n]부터 [0, 0]까지 prefix sum 구함.
        // 2차원 prefix sum 값 설정`
        for(int i = 0; i<=maxr; i++){
            for(int j = 0; j<=maxc; j++){
                psum[i][j] = 0;
            }
        }

        for(int i = maxr-1; i>=0; i--){
            for(int j = maxc-1; j>=0; j--){
                psum[i][j] += psum[i+1][j] + psum[i][j+1] - psum[i+1][j+1] + (pizza[i][j] == 'A');
            }
        }

        // dp[i][j][k] : 좌표 i, j를 k번 cutting해야 할 때 경우의 수
        return DFS(0, 0, k-1); // *** 실수 : 주어진 k는 조각의 개수. 따라서 k-1을 넣어야 함
    }
};