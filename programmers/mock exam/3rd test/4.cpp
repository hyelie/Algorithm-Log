#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int N;
vector<int> visited;
vector<vector<int>> edges;

// .first : cur을 색 칠한 경우 최소 색칠 횟수, .second : cur을 색칠하지 않은 경우 최소 색칠 횟수
pii dfs(int cur){
    visited[cur] = true;

    pii result = {1, 0}; // .first : cur을 색칠한 경우 
    for(int adj : edges[cur]){
        if(!visited[adj]){
            pii child_result = dfs(adj);
            result.first += min(child_result.first, child_result.second);
            // cur을 색칠했다면 child는 색칠해도 되고, 안 해도 됨
            result.second += child_result.first;
            // cur을 색칠하지 않았다면 child을 색칠되어 있어야 함
        }
    }
    return result; // child가 없다면 {1, 0}을 리턴.
}

int solution(int n, vector<vector<int>> lighthouse) {
    N = n+1;
    visited.resize(N);
    fill(visited.begin(), visited.end(), false);
    edges.resize(N);
    for(vector<int>& vi : lighthouse){
        edges[vi[0]].push_back(vi[1]);
        edges[vi[1]].push_back(vi[0]);
    }

    pii answer = dfs(1);

    return min(answer.first, answer.second);
}

/*
root부터 dfs, 
*/