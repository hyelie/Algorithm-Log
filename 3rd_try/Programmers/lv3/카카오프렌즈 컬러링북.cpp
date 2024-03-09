#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii; // [r, c]

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int m, n;

vector<vector<int>> board;
vector<vector<bool>> visited;

int bfs(int i, int j, int color){
    int cnt = 0;
    
    // bfs init: push할 때 visited
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;
    cnt++;
    
    // bfs
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        
        for(int d = 0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && !visited[nr][nc] && board[nr][nc] == color){
                q.push({nr, nc});
                visited[nr][nc] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int _m, int _n, vector<vector<int>> picture) {
    m = _m; n = _n;
    board = picture;
    
    vector<vector<bool>> _visited(m, vector<bool>(n, false)); visited = _visited;
    
    int num_section = 0;
    int max_value = -1;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(!visited[i][j] && board[i][j] != 0){
                num_section++;
                max_value = max(max_value, bfs(i, j, board[i][j]));
            }
        }
    }
    
    return {num_section, max_value};
}