#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = 1e9;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

struct Pos{
    int prev_dir; // 이전의 진행방향, 0이 가로, 1이 세로
    int r, c; // 좌표
    int num_s = 0; // 직전 개수
    int num_c = 0; // 코너 개수
};

bool IsEnd(Pos cur){
    return cur.r == n-1 && cur.c == n-1;
}

int CalSum(Pos cur){
    return cur.num_s * 100 + cur.num_c * 500;
}

int GetDirection(int r, int c, int nr, int nc){ // 0이면 가로, 1이면 세로
    if(r == nr) return 0;
    else return 1;
}

// 현재 위치 [r, c], 다음 위치 [nr, nc]에 대해 Pos 리턴
Pos GetNext(Pos cur, int nr, int nc){
    Pos next;
    next.r = nr;
    next.c = nc;
    next.num_s = cur.num_s;
    next.num_c = cur.num_c;

    if(next.r == 21845){
        cout<<"e"<<endl;
    }
    
    next.prev_dir = GetDirection(cur.r, cur.c, nr, nc); // 방향 계산
    if(cur.prev_dir == next.prev_dir) next.num_s++; // 방향에 따른 도로 종류++
    else next.num_c++;
}

void backtrack(Pos cur){
    if(IsEnd(cur)){
        // 결과 계산
        answer = min(answer, CalSum(cur));
        return;
    }
        
    // 현 위치 기준, 상하좌우 unvisited && 벽 없는 경우
    for(int d = 0; d<4; d++){
        int nr = cur.r + dr[d];
        int nc = cur.c + dc[d];
        
        if(0 <= nr && nr < n && 0 <= nc && nc < n && !visited[nr][nc] && board[nr][nc] == 0){            
            visited[nr][nc] = true;
            Pos next = GetNext(cur, nr, nc);
            backtrack(next);
            visited[nr][nc] = false;
        }
    }
}

int solution(vector<vector<int>> _board) {
    // var init
    n = _board.size();
    board = _board;
    vector<vector<bool>> _visited(n, vector<bool>(n, false));
    visited = _visited;
    
    Pos cur;
    cur.r = 0; cur.c = 0; cur.num_s = 0; cur.num_c = 0;
    
    // 첫 도로 가로방향 세로방향에 대해 각각 1번
    cur.prev_dir = 0;
    visited[0][0] = true;
    backtrack(cur);
    
    cur.prev_dir = 1;
    backtrack(cur);

    cout<<answer<<endl;
    
    return answer;
}

/*
backtrack + 빡구현
*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	vector<vector<int>> t = {{0,0,0},{0,0,0},{0,0,0}};

	solution(t);
	
	return 0;
}