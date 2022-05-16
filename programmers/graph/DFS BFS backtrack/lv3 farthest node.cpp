// 가장 먼 노드

#include <string>
#include <vector>
#include <iostream>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> vertex(n+1, -1);
    vertex[1] = 0;
    queue<int> q; q.push(1);
    
    vector<vector<int>> edge_list(n+1);
    for(vector<int> e : edge){
        edge_list[e[0]].push_back(e[1]);
        edge_list[e[1]].push_back(e[0]);
    }
    
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int to : edge_list[front]){
            if(vertex[to] == -1){
                vertex[to] = vertex[front] + 1;
                q.push(to);
            }
        }
    }
    
    int max_value = -1;
    for(int i : vertex){
        if(i != -1) max_value = max(max_value, i);
    }
    int cnt = 0;
    for(int i : vertex){
        if(i == max_value) cnt++;
    }
    return cnt;
}

// BFS
// bellman-ford. 각 edge weight = 1로 두면 됨