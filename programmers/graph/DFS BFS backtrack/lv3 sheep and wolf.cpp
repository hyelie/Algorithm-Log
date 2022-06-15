// 양과 늑대

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

vector<int> parent(17, -1); // parnet[i] : i의 parent node
vector<vector<int>> child(17);
vector<int> infos;
int answer = -1;

// candidates : 후보
void DFS(int cur_node, int num_sheep, int num_wolf, vector<bool> candidates){
    vector<int> can_go; // 탐색 가능한 노드들
    int diff = num_sheep - num_wolf;
    for(int i = 0; i<candidates.size(); i++){
        if(candidates[i] == false) continue;
        if(diff - infos[i] > 0) can_go.push_back(i);
    }
    
    if(can_go.size() == 0){ // 종료 조건
        answer = max(answer, num_sheep);
        return;
    }
    
    for(int node : can_go){ // 탐색 가능한 노드들로 DFS
        candidates[node] = false;
        for(int c : child[node]){
            candidates[c] = true;
        }
        
        if(infos[node] == 0) DFS(node, num_sheep+1, num_wolf, candidates);
        else DFS(node, num_sheep, num_wolf + 1, candidates);
        
        candidates[node] = true;
        for(int c : child[node]){
            candidates[c] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int num_node = info.size();
    infos = info;
    for(vector<int> edge : edges){
        parent[edge[1]] = edge[0];
        child[edge[0]].push_back(edge[1]);
    }
    
    vector<bool> candidates(num_node, false);
    for(int c : child[0]){
        candidates[c] = true;
    }
    DFS(0, 1, 0, candidates);
    
    return answer;
}