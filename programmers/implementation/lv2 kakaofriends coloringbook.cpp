// 카카오프렌즈 컬러링북

#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

pii findUnvisited(int m, int n, vector<vector<bool>>& visited){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(!visited[i][j]){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(picture[i][j] == 0){
                visited[i][j] = true;
            }
        }
    }
    
    // DFS는 경로를 못 찾을 수도 있으니.. BFS로 하자.
    int num_area = 0;
    int max_area = 0;
    queue<pii> q;
    while(1){
        // .first : row, .second : col
        pii point = findUnvisited(m, n, visited);
        if(point.first == -1) break;
        q.push(point);
        num_area++;
        int temp_area = 0, cur_color = picture[point.first][point.second];
        do{
            point = q.front(); q.pop();
            //if(visited[point.first][point.second]) continue;
            visited[point.first][point.second] = true;
            temp_area++;
            for(int i = 0; i<4; i++){
                int nr = point.first + dr[i];
                int nc = point.second + dc[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && !visited[nr][nc] && picture[nr][nc] == cur_color){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }while(!q.empty());
        max_area = max(max_area, temp_area);
    }
    
    vector<int> answer(2);
    answer[0] = num_area;
    answer[1] = max_area;
    return answer;
    
    
}