// 경주로 건설

#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
struct rd{
    int row;
    int col;
    int dir;
};

int MAX = 2100000000, answer = MAX;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
// 0 : down, 1 : right, 2 : up, 3 : left

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<vector<int>>> road(n, vector<vector<int>>(n, vector<int>(4, MAX)));
    for(int i = 0; i<4; i++){road[0][0][i] = 0;};
    queue<rd> q;
    rd d; d.row = 0; d.col=0; d.dir=-1;
    q.push(d);
    while(!q.empty()){
        d = q.front(); q.pop();
        if(d.row == n-1 && d.col == n-1){
            answer = min(answer, road[n-1][n-1][d.dir]);
            continue;
        }
        for(int next_dir = 0; next_dir < 4; next_dir++){
            int next_r = d.row + dr[next_dir];
            int next_c = d.col + dc[next_dir];
            int cur_cost = road[d.row][d.col][d.dir];
            int next_cost = road[next_r][next_c][next_dir];
            if(0 > next_r || next_r >= n || 0 > next_c || next_c >= n || board[next_r][next_c] == 1 || next_cost < cur_cost) continue;
            
            cur_cost += 100;
            if(d.dir == 0 || d.dir == 2){
                if(next_dir == 1 || next_dir == 3){
                    cur_cost += 500;
                }
            }
            if(d.dir == 1 || d.dir == 3){
                if(next_dir == 0 || next_dir == 2){
                    cur_cost += 500;
                }
            }
            if(next_cost > cur_cost){
                road[next_r][next_c][next_dir] = cur_cost;
                rd n; n.dir = next_dir; n.row = next_r; n.col = next_c;
                q.push(n);
            }
            
        }
        
    }
    
    return answer;
}