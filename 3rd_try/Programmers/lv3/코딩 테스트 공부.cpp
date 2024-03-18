#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int INF = 1e9;
int MAX = 150;
vector<vector<int>> dp(151, vector<int>(151, INF)); // dp[i][j] : 알고력 i, 코딩력 j를 만들기 위한 최소 시간
int max_alp = -1, max_cop = -1;

int solution(int alp, int cop, vector<vector<int>> problems) {
    // max setup
   
    for(vector<int>& problem: problems){
        max_alp = max(max_alp, problem[0]);
        max_cop = max(max_cop, problem[1]);
    }
    
    // dp init, 2사분면
    for(int i = 0; i<=alp; i++){
        for(int j = 0; j<=cop; j++){
            dp[i][j] = 0;
        }
    }
    // 3사분면
    for(int i = alp + 1; i<=MAX; i++){
        for(int j = 0; j<=cop; j++){
            dp[i][j] = i - alp;
        }
    }
    // 1사분면
    for(int i = 0; i<=alp; i++){
        for(int j = cop + 1; j<=MAX; j++){
            dp[i][j] = j - cop;
        }
    }
    // 4사분면
    for(int i = alp+1; i<=MAX; i++){
        for(int j = cop+1; j<=MAX; j++){
            dp[i][j] = i - alp + j - cop;
        }
    }
    
    for(int i = alp; i<=MAX; i++){
        for(int j = cop; j<=MAX; j++){
            int alp_result, cop_result;
            // alp++
            alp_result = min(MAX, i + 1);
            cop_result = min(MAX, j);
            dp[alp_result][cop_result] = min(dp[alp_result][cop_result], dp[i][j] + 1);
            // cop++
            alp_result = min(MAX, i);
            cop_result = min(MAX, j+1);
            dp[alp_result][cop_result] = min(dp[alp_result][cop_result], dp[i][j] + 1);
            // 모든 문제에 대해, 풀 수 있는것들은 전부 다.
            for(int k = 0; k<problems.size(); k++){
                vector<int> problem = problems[k];
                if(i >= problem[0] && j >= problem[1]){
                    int alp_result = min(MAX, i + problem[2]);
                    int cop_result = min(MAX, j + problem[3]);
                    dp[alp_result][cop_result] = min(dp[alp_result][cop_result], dp[i][j] + problem[4]);
                }
            }
        }
    }
    
    int answer = INF;
    for(int i = max_alp; i<=MAX; i++){
        for(int j = max_cop; j<=MAX; j++){
            answer = min(answer, dp[i][j]);
        }
    }
    return answer;
}