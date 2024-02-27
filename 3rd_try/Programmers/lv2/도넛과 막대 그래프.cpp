#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
// 정점 번호, 도넛, 막대, 8

int maxN = 1000001;
vector<vector<int>> edges(maxN);
vector<int> indegree(maxN), outdegree(maxN);
vector<bool> visited(maxN, false);

int num_o = 0, num_bar = 0, num_8 = 0;

void dfs(int cur){
    if(edges[cur].size() == 0){
        num_bar++;
        return;
    }
    
    if(edges[cur].size() >= 2){
        num_8++;
        return;
    }
    
    if(visited[cur]){
        num_o++;
        return;
    }
    
    visited[cur] = true;
    
    for(int next : edges[cur]){
        dfs(next);
    }
    
}

vector<int> solution(vector<vector<int>> _edges) {
    // init
    for(vector<int> edge : _edges){
        int from = edge[0], to = edge[1];
        edges[from].push_back(to);
        indegree[to]++; outdegree[from]++;
    }
    
    // 삽입된거
    int inserted_node = 0;
    for(int i = 0; i<maxN; i++){
        if(indegree[i] == 0 && outdegree[i] >= 2) inserted_node = i;
    }
    
    // DFS
    for(int start : edges[inserted_node]){
        dfs(start);
    }
    
    return {inserted_node, num_o, num_bar, num_8};
}

/*
DFS 돌리면 될 것 같은...

1. 추가된 vertex를 찾아야 한다.
도넛 : in & out 동일하게 1.
막대 : in도 1개, out도 1개, 마지막 건 없음.
8자 : 마찬가지로 in & out 동일.

그러면 in이 out보다 더 많은 것 찾으면 되겠네. 동시에 out은 0이 아니어야 함.
아니.. in이 0인 거 네?

2. 각각 몇개인지 찾아야 한다.
DFS 하는 게 편할 듯.
막대 : BFS 중에, 더 이상 out이 없을 때
도넛 : BFS 중에 다시 첫 노드로 돌아오는 경우.
8 : 탐색 중에 "중앙 노드"가 찾아지는 경우. "중앙 노드"는 out이 2개임.

1시간 20분, in이 없고 out이 2 이상이어야 하는 것 같음.
*/