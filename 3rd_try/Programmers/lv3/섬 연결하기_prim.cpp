#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // .first : vertex, .second : weight

struct comp{ // weight가 작은 것 - vertex가 작은 것 순으로.
    bool operator() (const pii &a, const pii &b) const {
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }  
};



int solution(int n, vector<vector<int>> costs) {
    priority_queue<pii, vector<pii>, comp> pq;
    
    // init
    vector<vector<pii>> edges(n); // edges[i] : vertex i의 outgoing edge, [dest, weight]
    for(vector<int> &cost : costs){
        int from = cost[0], to = cost[1], weight = cost[2];
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }
    
    vector<bool> visited(n, false);
    
    // prim init
    visited[0] = true;
    for(pii &edge : edges[0]){
        int dest = edge.first, weight = edge.second;
        pq.push({dest, weight});
    }
        
    // prim
    int answer = 0;
    while(!pq.empty()){
        int dest = pq.top().first, weight = pq.top().second;
        pq.pop();
        
        if(!visited[dest]){
            answer += weight;
            visited[dest] = true;
            for(pii &edge : edges[dest]){
                int next = edge.first, next_weight = edge.second;
                pq.push({next, next_weight});
            }
        }
    }
    
    return answer;
}

/*
union-find
prim, kruskal
둘 다로 한 번?
*/