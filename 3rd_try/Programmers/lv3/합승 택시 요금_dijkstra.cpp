#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // [to, weight]

vector<vector<pii>> edges;

struct comp{ // weight 작은 것 - index 작은 것
    bool operator() (const pii &a, const pii &b) const{
        if(a.second == b.second){
            return a > b;
        }
        return a.second > b.second;
    }
};

int INF = 1e8;
vector<int> dijkstra(int start, int n){
    vector<int> dists(n+1, INF);
    dists[start] = 0;
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push({start, dists[start]});
    
    while(!pq.empty()){
        int cur = pq.top().first;
        pq.pop();
        
        for(pii nexts : edges[cur]){
            int next = nexts.first, next_weight = nexts.second;
            if(dists[next] > dists[cur] + next_weight){
                dists[next] = dists[cur] + next_weight;
                pq.push(nexts);
            }
        };
    }
    
    return dists;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // edge init
    edges.resize(n+1);
    for(vector<int> &fare : fares){
        int from = fare[0], to = fare[1], weight = fare[2];
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }
    
    // cal
    vector<int> a_to_all = dijkstra(a, n);
    vector<int> b_to_all = dijkstra(b, n);
    vector<int> s_to_all = dijkstra(s, n);
    
    int answer = INF;
    
    for(int i = 1; i<=n; i++){
        int temp = s_to_all[i] + a_to_all[i] + b_to_all[i];
        answer = min(temp, answer);
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