// 네트워크

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<bool>& visited, vector<vector<int>>& computers){
    visited[node] = true;
    
    int n = computers[node].size();
    for(int i = 0; i<n; i++){
        if(i == node) continue;
        if(computers[node][i] && !visited[i]) DFS(i, visited, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    
    int answer = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            answer++;
            DFS(i, visited, computers);
        }
    }
    
    return answer;
}