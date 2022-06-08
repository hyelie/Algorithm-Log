// 합승 택시 요금

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, 10000000));
    for(int i = 1; i<=n; i++){
        dist[i][i] = 0;
    }
    for(vector<int> vi : fares){
        dist[vi[0]][vi[1]] = dist[vi[1]][vi[0]] = vi[2];
    }
    for(int temp = 1; temp <= n; temp++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                dist[from][to] = min(dist[from][to], dist[from][temp] + dist[temp][to]);
            }    
        }
    }
    
    int answer = 987654321;
    for(int i = 1; i<=n; i++){
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}