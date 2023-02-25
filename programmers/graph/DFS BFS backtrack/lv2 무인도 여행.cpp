#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // .first : r, .second : c

vector<int> answer;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void BFS(pii cur, vector<vector<bool>> &visited, vector<string> maps, int maxr, int maxc){
    queue<pii> q;
    q.push(cur);
    int food = 0;
    
    while(!q.empty()){
        pii top = q.front(); q.pop();
        visited[top.first][top.second] = true;
        food += maps[top.first][top.second] - '0';
        
        for(int i = 0; i<4; i++){
            int nr = dr[i] + top.first;
            int nc = dc[i] + top.second;
            if(0 <= nr && nr < maxr && 0 <= nc && nc < maxc && !visited[nr][nc] && '0' <= maps[nr][nc] && maps[nr][nc] <= '9'){
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    
    answer.push_back(food);
}

vector<int> solution(vector<string> maps) {
    int maxr = maps.size(), maxc = maps[0].length();
    vector<vector<bool>> visited(maxr, vector<bool>(maxc, false));
    
    
    for(int i = 0; i<maxr; i++){
        for(int j = 0; j<maxc; j++){
            if(!visited[i][j] && '0' <= maps[i][j] && maps[i][j] <= '9'){
                BFS({i, j}, visited, maps, maxr, maxc);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.size() == 0) answer = {-1};
    return answer;
}