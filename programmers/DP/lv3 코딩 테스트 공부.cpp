#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

// problem[i] : [alp_req, cop_req, alp_rwd, cop_rwd, cost]
int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = alp, max_cop = cop; // 오류 : INT_MIN으로 초기화하면 max_alp가 alp보다 작은 경우를 처리하지 못함
    for(vector<int>& problem : problems){
        max_alp = max(max_alp, problem[0]);
        max_cop = max(max_cop, problem[1]);
    }

    vector<vector<int>> dp(max_alp + 1, vector<int>(max_cop + 1, INT_MAX));   
    dp[alp][cop] = 0;
    
    for(int i = alp; i<=max_alp; i++){
        for(int j = cop; j<=max_cop; j++){
            if(i+1 <= max_alp) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if(j+1 <= max_cop) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            
            for(vector<int> &problem : problems){
                int alp_req = problem[0], cop_req = problem[1], alp_rwd = problem[2], cop_rwd = problem[3], cost = problem[4];
                if(alp_req <= i && cop_req <= j){
                    int nexti = i+alp_rwd > max_alp ? max_alp : i+alp_rwd; // 오류 : MAX값으로 잡아버리면 max_alp값이 정확하게 갱신 안됨
                    int nextj = j+cop_rwd > max_cop ? max_cop : j+cop_rwd;
                    dp[nexti][nextj] = min(dp[nexti][nextj], dp[i][j] + cost);
                }
            }
        }
    }
    
    return dp[max_alp][max_cop];
}

/*
DP였다고..? ;;
dp[i][j] : alp i, cop j를 채우기 위해 걸리는 최소 시간
dp[i][j]에서
    dp[i+1][j] = dp[i][j] + 1
    dp[i][j+1] = dp[i][j] + 1
    모든 문제에 대해, 풀 수 있는 문제의 증가량 봐주면 될듯
    
    */