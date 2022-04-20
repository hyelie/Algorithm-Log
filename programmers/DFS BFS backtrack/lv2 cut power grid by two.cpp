// 전력망을 둘로 나누기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// DFS 후 size++
void DFS(int cur_node, vector<vector<int>>& adjacent, vector<bool>& visited, int &size){
    visited[cur_node] = true;
    size++;
    
    for(int i = 0; i<adjacent[cur_node].size(); i++){
        if(!visited[adjacent[cur_node][i]]){
            DFS(adjacent[cur_node][i], adjacent, visited, size);
        }
    }
}

// wires 중 'cut'번째 것을 잘랐을 때 adjecent vector return
vector<vector<int>> cut_one(int n, vector<vector<int>> wires, int cut){
    int size = wires.size();
    vector<vector<int>> adjacent(n+1);
    for(int i = 0; i<size; i++){
        if(i == cut) continue;
        adjacent[wires[i][0]].push_back(wires[i][1]);
        adjacent[wires[i][1]].push_back(wires[i][0]);
    }
    return adjacent;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 10001, size =wires.size();
    for(int i = 0; i<size; i++){
        vector<bool> visited(n+1, false); // visited[i] : i번째 node가 visited인지.
        vector<vector<int>> adjacent(n+1); // adjacent[i] : vector<int>, i번째 node와 연결된 node의 vector
        adjacent = cut_one(n, wires, i); 
        
        vector<int> tree_size(2, 0);
        for(int i = 1, tree_size_idx = 0; i<=n; i++){
            if(!visited[i]){
                DFS(i, adjacent, visited, tree_size[tree_size_idx]);
                tree_size_idx++;
            }
        }
        answer = min(answer, abs(tree_size[0] - tree_size[1]));
    }
    
    return answer;
}