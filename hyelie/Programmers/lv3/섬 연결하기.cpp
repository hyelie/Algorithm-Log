#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct cmp{
    bool operator()(pii &a, pii &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

priority_queue<pii, vector<pii>, cmp> pq;
vector<vector<pii>> edges;
vector<int> visited;

int solution(int n, vector<vector<int>> costs) {
    edges.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    for(vector<int> cost : costs){
        int from = cost[0], to = cost[1], weight = cost[2];
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }
    
    // prim
    visited[0] = true;
    for(pii e : edges[0]) pq.push(e);
    
    int answer = 0;
    while(!pq.empty()){
        pii front = pq.top(); pq.pop();
        if(visited[front.first]) continue;
        
        visited[front.first] = true;
        answer += front.second;
        for(pii e : edges[front.first]) pq.push(e);
    }
    
    return answer;
}