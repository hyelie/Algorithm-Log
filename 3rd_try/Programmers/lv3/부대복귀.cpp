#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> pii; // .first : node, .second : weight

int INF = 1e8;

struct comp{
  bool operator() (const pii &a, const pii &b) { // weight 작은 것 -> node 작은 것
      if(a.second == b.second) return a.first > b.first;
      return a.second > b.second;
  }  
};
priority_queue<pii, vector<pii>, comp> pq;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    // edge init
    map<int, vector<int>> edges;
    for(vector<int> &road : roads){
        int from = road[0], to = road[1];
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    // dijkstra init
    vector<int> dist(n+1, INF);
    dist[destination] = 0;
    pq.push({destination, 0});
    
    // dijkstra
    while(!pq.empty()){
        int cur = pq.top().first, cur_weight = pq.top().second;
        pq.pop();
        
        for(int next : edges[cur]){
            // 갱신 가능해야 update
            if(dist[next] > dist[cur] + 1){
                dist[next] = dist[cur] + 1;
                pq.push({next, dist[next]});
            }
        }
    }
    
    vector<int> answer(sources.size());
    for(int i = 0; i<sources.size(); i++){
        answer[i] = (dist[sources[i]] == INF) ? -1 : dist[sources[i]];
    }
    return answer;
}

/*
1부터 source까지 min dist를 찾으면 된다.
여기서는 weight가 1이지만. dijkstra로 풀어볼까?
*/