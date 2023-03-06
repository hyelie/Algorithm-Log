#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int UNVISITED = -1;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    // initialize
    vector<int> dist(n + 1, UNVISITED);
    map<int, vector<int>> edges; // edges[i] : i를 출발점으로 하는 edge
    for(vector<int> road : roads){
        edges[road[0]].push_back(road[1]);
        edges[road[1]].push_back(road[0]);
    }
    
    // BFS init
    queue<int> q;
    q.push(destination);
    dist[destination] = 0; // dist 초기화는 q에 넣는 순간
    
    // BFS`
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int next : edges[cur]){
            if(dist[next] == UNVISITED){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    // get answer
    vector<int> answer;
    for(int s : sources){
        answer.push_back(dist[s]);
    }
    return answer;
}


// weight가 1이니까, BFS가 적절할 것 같다.
// destination부터 탐색