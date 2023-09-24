#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // .first : to, .second : dist

queue<pii> q;
vector<vector<int>> edges;

int solution(int n, vector<vector<int>> edge) {
    vector<int> visited(n+1, -1);
    edges.resize(n+1);
    for(vector<int> e : edge){
        int from = e[0], to = e[1];
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    q.push({1, 0});
    visited[1] = 0;
    
    int max_value = -1;
    while(!q.empty()){
        pii front = q.front(); q.pop();
        
        for(int next : edges[front.first]){
            if(visited[next] != -1) continue;
            
            visited[next] = front.second + 1;
            q.push({next, front.second + 1});
            max_value = max(max_value, visited[next]);
        }
    }
    
    int answer = 0;
    for(int v : visited) if(v == max_value) answer++;
    return answer;
}