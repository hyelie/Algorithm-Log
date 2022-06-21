// GPS

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int INF = 987654321;
    vector<vector<int>> dp(k, vector<int>(n+1, INF));
    // dp[t][l] : 시간 t의 위치가 l일 때 최소 수정 횟수
    // dp[A][B] = min(dp[A-1][B의 edge들 + B] + gps_logs[A] == B ? 1 : 0) // 현재 위치 고쳤는지

    vector<vector<int>> edges(n+1); // edges[i] : vertex list connected with vertex i
    for(vector<int> edge : edge_list){
        edges[edge[0]].push_back(edge[1]);
        edges[edge[1]].push_back(edge[0]);
    }
    for(int i = 1; i<=n; i++){
        edges[i].push_back(i);
    }
    
    dp[0][gps_log[0]] = 0;
    for(int t = 1; t<k; t++){
        for(int l = 1; l<=n; l++){ // l : current_vertex
            for(int adjacent : edges[l]){
                dp[t][l] = min(dp[t-1][adjacent] + (gps_log[t] == l ? 0 : 1), dp[t][l]);
            }
        }
    }
    
    
    int answer = dp[k-1][gps_log[k-1]];
    return answer >= INF ? -1 : answer;
}

/*


// 자기 자신도 +

dp[0][all] = 0

*/
