#include <string>
#include <vector>
#include <climits>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

struct Edge{
    int dest;
    int weight;
};

// weight가 작은 것이 top
struct cmp{
    bool operator() (const Edge&a, const Edge&b){
        if(a.weight == b.weight) return a.dest > b.dest;
        return a.weight > b.weight;
    }
};

bool isExists(int n, set<int>& s){
    if(s.find(n) == s.end()) return false;
    return true;
}
    
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    // init
    set<int> Gates, Summits; // 출입구, 산봉우리
    for(int i : gates) Gates.insert(i);
    for(int i : summits) Summits.insert(i);
    
    // flip : 갔다가 돌아오는 게 아니라, gate로부터 summit까지만 가면 됨.
    // 따라서 gate에서는 outgoing edge만, summit에서는 incoming edge만 남겨야 함.
    vector<vector<Edge>> Edges(n+1);
    for(vector<int>& path : paths){
        bool isPath0Gate = isExists(path[0], Gates), isPath1Gate = isExists(path[1], Gates);
        bool isPath0Summit = isExists(path[0], Summits), isPath1Summit = isExists(path[1], Summits);
        if(isPath0Gate && isPath1Gate){} // gate를 연결하는 edge
        else if(isPath0Summit && isPath1Summit){} // summit을 연결하는 edge
        else if(isPath0Gate || isPath1Summit){ // gate에서는 나가기만 해야 하고, summit으로는 들어오기만 해야함
            Edge e1; e1.dest = path[1]; e1.weight = path[2];
            Edges[path[0]].push_back(e1);    
        }
        else if(isPath1Gate || isPath0Summit){
            Edge e2; e2.dest = path[0]; e2.weight = path[2];
            Edges[path[1]].push_back(e2);    
        }
        else{
            Edge e1; e1.dest = path[1]; e1.weight = path[2];
            Edges[path[0]].push_back(e1);
            Edge e2; e2.dest = path[0]; e2.weight = path[2];
            Edges[path[1]].push_back(e2);
        }
    }
    
    // dijkstra init
    // 모든 gate를 시작점으로 dijkstra해볼 수 없음.
    // flip : 모든 gate에서 weight를 0으로 두고, pq에 해당 edge 넣으면 그 점에서 시작 가능
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<int> dist(n+1, 987654321); // 실수 : INT_MAX로 하면 1만 더해도 overflow남. 적당한 수로 해야 함
    for(int v : gates){
        dist[v] = 0;
        Edge e; e.dest = v; e.weight = 0;
        pq.push(e);
    }
    
    // dijkstra
    while(!pq.empty()){
        int cur = pq.top().dest; pq.pop();
        
        for(Edge e : Edges[cur]){
            int next = e.dest, weight = e.weight;
            if(dist[next] > max(dist[cur], weight)){
                // 실수 1 : sum이 아니라 max로 해야 문제 조건에 맞음
                // 실수 2 : >=로 해버리면 무한루프 돌 수 있기 때문에 >로 해야 함
                dist[next] = max(dist[cur], weight);
                Edge nextE; nextE.dest = next; nextE.weight = dist[next];
                pq.push(nextE);
            }
        }
    }
    
    vector<int> answer = {-1, INT_MAX}; // v, intensity
    for(int v : Summits){
        if(dist[v] < answer[1]){
            answer[0] = v;
            answer[1] = dist[v];
        }
    }
    
    return answer;
}