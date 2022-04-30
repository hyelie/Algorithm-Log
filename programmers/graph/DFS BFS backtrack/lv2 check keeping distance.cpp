// 거리두기 확인하기

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int cur_d, int max_d, pii prev_position, vector<string>& places, vector<vector<bool>> visited, int& near_people){
    if(cur_d == max_d) return;
    
    int x = prev_position.first, y = prev_position.second;
    visited[x][y] = true;
    for(int i = 0; i<4; i++){
        int mx = x + dx[i], my = y + dy[i];
        if(0 <= mx && mx < 5 && 0 <= my && my < 5 && !visited[mx][my] && places[mx][my] != 'X'){
            visited[mx][my] = true;
            if(places[mx][my] == 'P') near_people++;
            DFS(cur_d + 1, max_d, {mx, my}, places, visited, near_people);
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int p = 0; p<places.size(); p++){
        vector<pii> peoples;
        for(int r = 0; r<5; r++){
            for(int c = 0; c<5; c++){
                if(places[p][r][c] == 'P') peoples.push_back({r, c});
            }
        }
        
        // BFS로 탐색, 파티션이 있는 경우는 탐색 X, 없는 경우는 계속 탐색.
        int near_people = 0;
        vector<vector<bool>> visited(5, vector<bool>(5, false));
        for(pii location : peoples){
            // location부터 Depth 2까지 DFS
            DFS(0, 2, location, places[p], visited, near_people);
        }
        answer.push_back(near_people == 0 ? 1 : 0);
    }

    return answer;
}