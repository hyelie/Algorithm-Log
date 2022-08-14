#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

// weight가 작은 것을 pq의 탑으로
struct cmp{
    bool operator()(pii &a, pii &b){
        if(a.second == b.second) return a.first < b.first;
        else return a.second > b.second;
    }
};

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> edges(n+1); // edges[i] : vertex i의 edge들
    for(vector<int>& edge : roads){
        int from = edge[0], to = edge[1];
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    int INF = 99999999;
    vector<int> dist(n+1, INF);
    dist[destination] = 0;

    priority_queue<pii, vector<pii>, cmp> pq; // .first : vertex, .second : weight
    pq.push({destination, 0});
    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        for(int adj : edges[cur.first]){
            if(dist[adj] > dist[cur.first] + 1){
                dist[adj] = dist[cur.first] + 1;
                pq.push({adj, dist[adj]});
            }
        }
    }

    vector<int> answer;
    for(int source : sources){
        answer.push_back(dist[source] == INF ? -1 : dist[source]);
    }
    return answer;
}

// destination으로부터 모든 점까지 dijkstra 쓰면 될 것 같은데?