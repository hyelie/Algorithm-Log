// 순위

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> dist(n+1, vector<int>(n+1, -1)); // dist[i][j] : dist of i to j. -1 : INF
    for(vector<int> v : results){
        dist[v[0]][v[1]] = 1;
    }
    for(int i = 1; i<=n; i++){
        dist[i][i] = 0;
    }
    
    for(int temp = 1; temp <= n; temp++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to<=n; to++){
                if(from == to) continue;
                if(dist[from][temp] == 1 && dist[temp][to] == 1){
                    dist[from][to] = 1;
                }
            }
        }
    }
    
    int answer = 0;
    for(int from = 1; from <= n; from++){
        int cnt = 0;
        for(int to = 1; to<=n; to++){
            if(dist[from][to] == 1 || dist[to][from] == 1){
                cnt++;
            }
        }
        if(cnt == n-1) answer++;
    }
    return answer;
}