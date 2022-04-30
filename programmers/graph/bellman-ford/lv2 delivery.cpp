// 배달

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2100000000

using namespace std;

typedef pair<int, int> pii;

int solution(int N, vector<vector<int>> road, int K) {      
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    for(int i = 1; i <= N; i++){
        // road[i][0] : 출발 edge, [i][1] : 도착 edge, [i][2] : weight
        for(int e = 0; e<road.size(); e++){
            if(dist[road[e][0]] != INF){
                dist[road[e][1]] = min(dist[road[e][0]] + road[e][2], dist[road[e][1]]);
            }
            if(dist[road[e][1]] != INF){
                dist[road[e][0]] = min(dist[road[e][1]] + road[e][2], dist[road[e][0]]);
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i<=N; i++){
        cout<<dist[i]<<endl;
        if(dist[i] <= K) answer++;
    }

    return answer;
}

// 벨만포드. O(V^2E)