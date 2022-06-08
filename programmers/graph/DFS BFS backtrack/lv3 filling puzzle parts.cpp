// 퍼즐 조각 채우기

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


typedef pair<int, int> pii;

pii d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pii operator +(const pii &a, const pii &b){
    return {a.first + b.first, a.second + b.second};
}

vector<vector<vector<int>>> table_parts, board_parts;

vector<vector<int>> rotate(vector<vector<int>> part){
    int rsize = part.size(), csize = part[0].size();
    vector<vector<int>> result(csize, vector<int>(rsize, 0));
    for(int i = 0; i<rsize; i++){
        for(int j = 0; j<csize; j++){
            result[csize - 1 - j][i] = part[i][j];
        }
    }
    return result;
}

void BFS(vector<vector<int>>& board, int i, int j, int size, int type){
    queue<pii> q;
    q.push({i, j});
    vector<pii> vpii;
    vpii.push_back({i, j});
    
    pii min_p = {i, j};
    board[i][j] = 0;
    while(!q.empty()){
        pii f = q.front(), n; q.pop();
        for(int i = 0; i<4; i++){
            n = f + d[i];
            if(0 <= n.first && n.first < size && 0 <= n.second && n.second < size && board[n.first][n.second] == type){
                board[n.first][n.second] = 1-type;
                vpii.push_back(n);
                q.push(n);
                min_p.first = min(min_p.first, n.first);
                min_p.second = min(min_p.second, n.second);
            }
        }
    }
    
    int height = -1, width = -1;
    for(pii &p : vpii){
        p.first -= min_p.first;
        p.second -= min_p.second;
        height = max(height, p.first);
        width = max(width, p.second);
    }
    
    height++; width++;
    vector<vector<int>> part(height, vector<int>(width, 0));
    for(pii &p : vpii){
        part[p.first][p.second] = 1;
    }
    
    if(type == 1){
        table_parts.push_back(part);    
    } else{
        board_parts.push_back(part);
    }
    
}

int countOne(vector<vector<int>>& v){
    int cnt = 0;
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            if(v[i][j] == 1) cnt++;
        }
    }
    return cnt;
}

bool isMatch(vector<vector<int>> &a, vector<vector<int>>& b){
    int arsize = a.size(), acsize = a[0].size(), brsize = b.size(), bcsize = b[0].size();
    if(!(arsize == brsize && acsize == bcsize)){
        return false;
    }
    for(int i = 0; i<arsize; i++){
        for(int j = 0; j<acsize; j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    int size = table.size();
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(table[i][j] == 1){
                BFS(table, i, j, size, 1);
            }
            if(game_board[i][j] == 0){
                BFS(game_board, i, j, size, 0);
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i<board_parts.size(); i++){
        int cnt = countOne(board_parts[i]);
        for(int j = 0; j<table_parts.size(); j++){
            bool flag = false;
            for(int r = 0; r<4; r++){
                table_parts[j] = rotate(table_parts[j]);
                flag = isMatch(board_parts[i], table_parts[j]);
                if(flag){
                    answer += cnt;
                    table_parts.erase(table_parts.begin() + j);
                    j = table_parts.size();
                    break;
                }
            }
        }
    }
    
    return answer;
}

/*

일단 table에서 조각들 모두 추출하고 - DFS로 connected인 것 추출 가능
game_board에서 빈 칸 모두 추출하고 - 이 두개가 맞나 볼까... 아니면

table에서 추출한 것에서 하나하나 넣어볼까

*/