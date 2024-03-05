#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int answer = 1e9;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

struct Pos{
    int r, c, prev_dir;
};

bool IsEnd(Pos cur){
    return cur.r == n-1 && cur.c == n-1;
}

int GetDirection(int r, int c, int nr, int nc){ // 0이면 가로, 1이면 세로
    if(r == nr) return 0;
    else return 1;
}

void bfs(int prev_dir){
    int INF = 1e9;
    vector<vector<vector<int>>> prices(n, vector<vector<int>>(n, vector<int>(2, INF)));
    // [r, c, 방향(가로 0, 세로 1)]
    
    queue<Pos> q;
    q.push({0, 0, prev_dir});
    prices[0][0][prev_dir] = 0;
    
    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        
        if(IsEnd(cur)){
            answer = min(answer, prices[cur.r][cur.c][cur.prev_dir]);
            continue;
        }
        
        for(int i = 0; i<4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            
            if(0 <= nr && nr < n && 0 <= nc && nc < n && !board[nr][nc]){
                // cur로부터 next로 갈 때 가격 계산
                int cur_price = prices[cur.r][cur.c][cur.prev_dir];
                cur_price += 100;
                
                int cur_dir = GetDirection(cur.r, cur.c, nr, nc); // 이전 진행 방향과 현재 진행 방향 계산
                if(cur_dir != cur.prev_dir) cur_price += 500; // 이전 진행 방향과 현재 진행 방향 다르면 꺾음
                
                if(cur_price < prices[nr][nc][cur_dir]){ // 가격 더 작을 때만 갱신
                    Pos next; next.r = nr; next.c = nc; next.prev_dir = cur_dir;
                    prices[nr][nc][cur_dir] = cur_price;
                    q.push(next);
                }
            }
        }
    }
}

int solution(vector<vector<int>> _board) {
    // var init
    n = _board.size();
    board = _board;
    vector<vector<bool>> _visited(n, vector<bool>(n, false));
    visited = _visited;
    
    // 첫 도로 가로방향 세로방향에 대해 각각 1번
    bfs(0);
    bfs(1);
    
    return answer;
}

/*
backtrack + 빡구현
*/