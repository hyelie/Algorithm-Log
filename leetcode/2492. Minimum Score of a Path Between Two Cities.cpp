typedef pair<int, int> pii;

struct cmp{
    bool operator()(pii &a, pii &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<vector<pii>> edges; // .first : 도착점, .second : weight
    vector<int> dists;
    priority_queue<pii, vector<pii>, cmp> pq; // .first : vertex, .second : weight
    int minScore(int n, vector<vector<int>>& roads) {
        // init
        edges.resize(n+1);
        dists.resize(n+1);
        fill(dists.begin(), dists.end(), INT_MAX);
        for(vector<int>& road : roads){
            edges[road[0]].push_back({road[1], road[2]});
            edges[road[1]].push_back({road[0], road[2]});
        }

        // dijkstra
        // dists[1] = 0; *** 실수 : 0으로 하면 전부 다 0이 됨
        pq.push({1, dists[1]}); 
        while(!pq.empty()){
            int curVertex = pq.top().first, curWeight = pq.top().second; pq.pop();

            for(pii edge : edges[curVertex]){
                int nextVertex = edge.first, nextWeight = edge.second;
                if(min(curWeight, nextWeight) < dists[nextVertex]){
                    dists[nextVertex] = min(curWeight, nextWeight);
                    pq.push({nextVertex, dists[nextVertex]});
                }
            }
        }

        return dists[n];
    }
};

// 100,000
// dij vs bfs