#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int INF = 1e9;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

struct info{
    int r;
    int c;
    int used;
    int dist;
};

int solution(int n, int m, vector<vector<int>> holes) {
    vector<vector<int>> board(m, vector<int>(n, 0)); // 0 : 빈칸, 1 : 함정
    // (m-1, 0)부터 (0, n-1)까지 가야 함.
    for(vector<int> hole : holes){
        int r = m - hole[1];
        int c = hole[0]-1;
        // cout<<r<<", "<<c<<endl;
        board[r][c] = 1;
    }
    
    vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(2, 0)));
    // visited[r][c][u] : (r, c) 위치를 방문했는지 여부. u가 1이면 신발 쓴 것이고, 0 신발 안 쓴 것.
    queue<info> q;
    info i; i.r = m-1; i.c = 0; i.used=0; i.dist=0;
    q.push(i);
    visited[m-1][0][0] = true;
    int answer = INF;
    while(!q.empty()){
        info cur = q.front(); q.pop();
        // cout<<"현재위치 : "<<cur.r<<", "<<cur.c<<", 사용여부 : "<<cur.used<<", dist : "<<cur.dist<<endl;
        
        // 종료조건
        if(cur.r == 0 && cur.c == n-1) answer = min(answer, cur.dist);
        
        // 안 쓰고 넘어가는 경우
        for(int d = 0; d<4; d++){
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && board[nr][nc] == 0 && !visited[nr][nc][cur.used]){
                // 사용 여부는 이전 상태 유지
                visited[nr][nc][cur.used] = true;
                info next; next.r = nr; next.c = nc; next.used = cur.used; next.dist = cur.dist+1;
                q.push(next);
            }
        }
        
        // 쓰고 넘어가는 경우
        if(cur.used == 1) continue;
        for(int d = 0; d<4; d++){
            int nr = cur.r + 2*dr[d];
            int nc = cur.c + 2*dc[d];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && board[nr][nc] == 0 && !visited[nr][nc][1]){
                visited[nr][nc][1] = true;
                info next; next.r = nr; next.c = nc; next.used = 1; next.dist = cur.dist+1;
                q.push(next);
            }
        }

    }

    return answer == INF ? -1 : answer;
}