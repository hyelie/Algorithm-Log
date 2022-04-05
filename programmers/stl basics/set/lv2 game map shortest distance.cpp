// 게임 맵 최단거리

#include<vector>
#include <queue>

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

using namespace std;

typedef pair<int, int> pii;

void BFS(pii max_rc, pii init_point, vector<vector<int>>& maps, vector<vector<int>>& dist, vector<vector<bool>>& visited){
    queue<pii> q;
    q.push(init_point);
    dist[init_point.first][init_point.second] = 1;
    visited[init_point.first][init_point.second] = true;
    
    while(!q.empty()){
        pii cur_point = q.front(); q.pop();
        if(cur_point == max_rc){
            return;
        }
        for(int i = 0; i<4; i++){
            pii next_point = cur_point;
            next_point.first += dr[i];
            next_point.second += dc[i];
            if(0 <= next_point.first && next_point.first <= max_rc.first && 0 <= next_point.second && next_point.second <= max_rc.second && maps[next_point.first][next_point.second] && !visited[next_point.first][next_point.second]){
                q.push(next_point);
                dist[next_point.first][next_point.second] = dist[cur_point.first][cur_point.second] + 1;
                visited[next_point.first][next_point.second] = true;
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    pii max_rc = {maps.size(), maps[0].size()};
    vector<vector<int>> dist(max_rc.first, vector<int>(max_rc.second, -1));
    vector<vector<bool>> visited(max_rc.first, vector<bool>(max_rc.second, false));
    BFS({max_rc.first-1, max_rc.second-1}, {0, 0}, maps, dist, visited);
    return dist[max_rc.first-1][max_rc.second-1];
}

// BFS ? -> 도달하면 바로 종료 및 해당 값 return. 이게 더 좋을 것임.
// DFS ? -> 모든 탐색 해 보아야 함. 오랜만에 DFS 쓰니까 너무 헷갈린당.

/*
void DFS(int max_r, int max_c, int r, int c, vector<vector<int>>& maps, vector<vector<bool>>& visited, vector<vector<int>>& dist, int cur_dist){
    if(r == max_r && c == max_c){
        dist[r][c] = min(dist[r][c], cur_dist);
        return;
    }
    dist[r][c] = cur_dist;
    for(int i = 0; i<4; i++){
        int tempr = r + dr[i];
        int tempc = c + dc[i];
        if(0 <= tempr && tempr <= max_r && 0 <= tempc && tempc <= max_c && maps[tempr][tempc] == 1 && !visited[tempr][tempc]){
            visited[tempr][tempc] = true;
            DFS(max_r, max_c, tempr, tempc, maps, visited, dist, cur_dist+1);
            visited[tempr][tempc] = false;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int max_r = maps.size(), max_c = maps[0].size();
    vector<vector<bool>> visited(max_r, vector<bool>(max_c, false));
    vector<vector<int>> dist(max_r, vector<int>(max_c, -1));
    dist[max_r-1][max_c-1] = 1000000;
    DFS(max_r-1, max_c-1, 0, 0, maps, visited, dist, 1);
    int answer = dist[max_r-1][max_c-1];
    return answer == 1000000? -1 : answer;
}
*/