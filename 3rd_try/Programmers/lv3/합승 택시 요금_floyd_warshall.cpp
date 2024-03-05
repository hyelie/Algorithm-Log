#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // dist init
    int INF = 1e8;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i = 1; i<=n; i++) dist[i][i] = 0;
    for(vector<int> fare : fares){
        int from = fare[0], to = fare[1], weight = fare[2];
        dist[from][to] = weight;
        dist[to][from] = weight;
    }
    
    // floyd-warshall
    for(int temp = 1; temp<=n; temp++){
        for(int from = 1; from<=n; from++){
            for(int to = 1; to<=n; to++){
                dist[from][to] = min(dist[from][to], dist[from][temp] + dist[temp][to]);
            }
        }
    }
    
    // cal
    int answer = INF;
    for(int i = 1; i<=n; i++){
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    return answer;
}

/*
s -> [어떤 점]
+ [어떤 점] -> A
+ [어떤 점] -> B

[어떤 점]은 s일수도 있음.

dijkstra 써서, A to all, B to all 구하고 + s to all 구하고

플로이드 와샬가 정석인 것 같긴 한데. 일단 dijkstra로 풀고 플로이드 와샬 풀자.

*/