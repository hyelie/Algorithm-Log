#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> edges;
vector<int> dist;
int INF = 1e9;
set<int> gate_set, summit_set;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    // edge init
    edges.resize(n+1);
    for(vector<int>& path: paths){
        edges[path[0]].push_back({path[1], path[2]});
        edges[path[1]].push_back({path[0], path[2]});
    }
    
    // dist & set & queue init
    queue<pii> q;
    dist.resize(n+1); fill(dist.begin(), dist.end(), INF);
    for(int gate: gates){
        gate_set.insert(gate);
        dist[gate] = 0;
        q.push({gate, 0}); // push all gates
    }
    
    // summit set init
    for(int summit: summits) summit_set.insert(summit);
    
    // bfs
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        int cur_num = cur.first, cur_intensity = cur.second;
        if(dist[cur_num] < cur_intensity || summit_set.find(cur_num) != summit_set.end()) continue; // 갱신 필요 없거나, 현 위치가 summit이면 더 탐색하면 안 됨.
        
        for(pii next: edges[cur_num]){ // .first: next vertex num, .second: cur - next weight
            int next_num = next.first, weight = next.second;
            if(gate_set.find(next_num) != gate_set.end()) continue; // gate면 skip
            
            int next_intensity = max(dist[cur_num], weight);
            if(next_intensity < dist[next_num]){
                // 갱신 가능
                dist[next_num] = next_intensity;
                q.push({next_num, dist[next_num]});
            }
        }
    }
    
    // cal answer
    sort(summits.begin(), summits.end(), less<int>());
    int min_summit = 0, min_intensity = INF;
    for(int summit : summits){
        if(dist[summit] < min_intensity){
            min_intensity = dist[summit];
            min_summit = summit;
        }
    }
    return {min_summit, min_intensity};
}