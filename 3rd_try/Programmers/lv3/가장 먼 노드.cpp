#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii; // .first : vertex index, .second : dist

int solution(int n, vector<vector<int>> edge) {
    // init
    int INF = 987654321;
    vector<int> dist(n+1, INF);
    vector<vector<int>> edges(n+1);
    for(vector<int> e : edge){
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }
    
    // bfs init
    queue<pii> q;
    
    q.push({1, 0});
    dist[1] = 0;
    
    // bfs
    while(!q.empty()){
        int cur = q.front().first;
        int cur_dist = q.front().second;
        q.pop();
                
        for(int next : edges[cur]){
            if(dist[next] != INF) continue;
            dist[next] = cur_dist + 1;
            q.push({next, dist[next]});
        }
    }
    
    // cal
    dist[0] = 0;
    int max_dist = *max_element(dist.begin(), dist.end());
    return count(dist.begin(), dist.end(), max_dist);
}