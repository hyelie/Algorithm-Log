#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int INF = -1;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    // edge init
    map<int, vector<int>> edges;
    for(vector<int> road : roads){
        int from = road[0], to = road[1];
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    // dfs init
    vector<int> dist(n+1, INF);
    dist[destination] = 0;
    queue<int> q;
    q.push(destination);
    
    // dfs
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(int next : edges[cur]){
            if(dist[next] == INF){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    // 정리
    vector<int> answer;
    for(int source : sources){
        answer.push_back(dist[source]);
    }
    return answer;
}

/*
1부터 source까지 min dist를 찾으면 된다.
여기서는 weight가 1이지만. dijkstra로 풀어볼까?
*/