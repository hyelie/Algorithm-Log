#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> land;
vector<vector<bool>> visited;
map<int, int> values; // [col, 연결된 석유 총 량]

void bfs(int r, int c){
    // bfs init 
    queue<pii> q;
    visited[r][c] = true;
    q.push({r, c});
    
    // 기타 변수
    set<int> cols;
    int size = 0;
    cols.insert(c);
    size++;
    
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        
        for(int i = 0; i<4; i++){
            int nr = cur.first + dr[i], nc = cur.second + dc[i];
            if(0 <= nr && nr < n && 0 <= nc && nc < m && land[nr][nc] == 1 && !visited[nr][nc]){
                visited[nr][nc] = true;
                q.push({nr, nc});
                cols.insert(nc);
                size++;
            }
        }
    }
    
    for(int col : cols){
        values[col] += size;
    }
}

int solution(vector<vector<int>> _land) {
    land = _land;
    n = land.size();
    m = land[0].size();
    
    
    vector<vector<bool>> _visited(n, vector<bool>(m, false)); visited = _visited;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visited[i][j] && land[i][j] == 1){
                bfs(i, j);
            }
        }
    }
    
    int answer = 0;
    for(auto [key, value] : values){
        answer = max(answer, value);
    }
    return answer;
}