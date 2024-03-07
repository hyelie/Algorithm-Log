#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int m, n, num_dir = 4;
vector<string> grid;
vector<vector<vector<bool>>> visited;
vector<int> answer;

// 위, 오른쪽, 아래, 왼쪽
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int get_next_dir(int prev_dir, char op){
    if(op == 'S'){
        return prev_dir; // 직진이면 그 방향 그대로
    }
    else if(op == 'R'){ // 우회전이면 +1
        return (prev_dir + num_dir + 1) % num_dir;
    }
    else{ // op == 'L' // 좌회전이면 -1
        return (prev_dir + num_dir - 1) % num_dir;
    }
}

void dfs(int i, int j, int dir, int len){   
    int nd = get_next_dir(dir, grid[i][j]);
    int nr = i + dr[nd]; if(nr == -1) nr = m-1; if(nr == m) nr = 0;
    int nc = j + dc[nd]; if(nc == -1) nc = n-1; if(nc == n) nc = 0;
    
    if(visited[nr][nc][nd]){
        answer.push_back(len);
        return;
    }
    
    visited[nr][nc][nd] = true;
    dfs(nr, nc, nd, len+1);
}

vector<int> solution(vector<string> _grid) {
    grid = _grid;
    m = grid.size(); n = grid[0].size();
    vector<vector<vector<bool>>> _visited(m, vector<vector<bool>>(n, vector<bool>(num_dir, false))); visited = _visited;
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<num_dir; k++){
                if(!visited[i][j][k]){
                    visited[i][j][k] = true;
                    dfs(i, j, k, 1);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end(), less<int>());
    return answer;
}

/*
backtrack인데,
이전 진행 방향 + 현재 칸에 따라서 진행 방향이 달라진다.

또, cycle을 찾았을 때, identical하게 구분해야 한다. ()

cycle을 찾는 조건은? [지났던 칸, 지났던 방향]을 또 들르는 것이다.
*/