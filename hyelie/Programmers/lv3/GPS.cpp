// 프로그래머스 GPS
// 이건 좀... 이딴게 DP?

#include <vector>

using namespace std;

/*
거점 개수가 200개
도로 개수는 10000개
BF같은데
dp[t][l] : 시간 t에서 위치가 l일 때
모든 dp[t-1][l의 neighbor]에 대해서 (이전단계)
gps_log[t] == l이면 +1
아니면 +0

*/

int INF = 1e9;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> edges(n+1);
    for(vector<int> e : edge_list){
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }
    for(int i = 1; i<=n; i++){
        edges[i].push_back(i);
    }
    
    vector<vector<int>> dp(k, vector<int>(n+1, INF));
    dp[0][gps_log[0]] = 0;
    for(int t = 1; t<k; t++){
        /*
        dp[t][l] : 시간 t에서 위치가 l일 때 고친 회수
        모든 dp[t-1][l의 neighbor]에 대해서 (이전단계)
        gps_log[t] == l이면 +1
        아니면 +0
        */
        
        for(int l = 1; l<=n; l++){
            int isLonT = gps_log[t] == l ? 0 : 1;
            for(int neighbor : edges[l]){
                dp[t][l] = min(dp[t-1][neighbor] + isLonT, dp[t][l]);
            }
        }
    }
    
    if(dp[k-1][gps_log[k-1]] >= INF) return -1;
    return dp[k-1][gps_log[k-1]];
}
