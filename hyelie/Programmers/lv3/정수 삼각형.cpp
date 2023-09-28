// 8분에 풀고 넘김
// 2분 추가로 씀
/*
간단한 DP 문제.
실수했던 점은 edge case 처리한 이후 일반 case 처리할 때
for문에 제일 마지막이 안 들어가게 설정했음
for(int i =1; i<h-1; i++)로 했음. 바로 위에서 h에 대해 했으므로, <=가 되었어야 했음.
*/

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    dp[0][0] = triangle[0][0];
    for(int h = 1; h<n; h++){ // height
        // 양쪽 끝 edge case 처리
        dp[h][0] = dp[h-1][0] + triangle[h][0];
        dp[h][h] = dp[h-1][h-1] + triangle[h][h];
        for(int i = 1; i<h; i++){ // 각 layer는 위에 2개 보고 큰 것으로 결정 가능
            dp[h][i] = max(dp[h-1][i], dp[h-1][i-1]) + triangle[h][i];
        }
    }
    
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}