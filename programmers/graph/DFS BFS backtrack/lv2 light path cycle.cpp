// 빛의 경로 사이클

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

// 0 : up, 1 : down, 2 : right, 3 : left
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int max_r, max_c;

int handleOutBound(int value, int max_value){
    if(0 > value) return max_value-1;
    else if(value >= max_value) return 0;
    else return value;
}

pii getNextNode(pii cur_point, int direction){
    cur_point.first = handleOutBound(cur_point.first + dr[direction], max_r);
    cur_point.second = handleOutBound(cur_point.second + dc[direction], max_c);
    return cur_point;
}

int getNextDirection(char next_char, int direction){
    if(next_char == 'L'){
        if(direction == 0) return 3;
        else if(direction == 1) return 2;
        else if(direction == 2) return 0;
        else if(direction == 3) return 1;
    } else if(next_char == 'R'){
        if(direction == 0) return 2;
        else if(direction == 1) return 3;
        else if(direction == 2) return 1;
        else if(direction == 3) return 0;
    } else{ // == 'S'
        return direction;
    }
}

int DFS(pii cur_point, int direction, vector<string>& grid, vector<vector<vector<bool>>>& visited, int cycle_len){
    if(visited[cur_point.first][cur_point.second][direction]){
        return cycle_len;
    }
    
    visited[cur_point.first][cur_point.second][direction] = true;
    pii next_point = getNextNode(cur_point, direction);
    int next_direction = getNextDirection(grid[next_point.first][next_point.second], direction);
    return DFS(next_point, next_direction, grid, visited, cycle_len+1);
}

vector<int> solution(vector<string> grid) {
    max_r = grid.size();
    max_c = grid[0].size();
    vector<int> answer;
    vector<vector<vector<bool>>> visited(max_r, vector<vector<bool>>(max_c, vector<bool>(4, false)));
    for(int r = 0; r<max_r; r++){
        for(int c = 0; c<max_c; c++){
            for(int d = 0; d<4; d++){
                int result = DFS({r, c}, d, grid, visited, 0);
                if(result) answer.push_back(result);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}