// 카드 짝 맞추기

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int boardsize = 4;
int INF = 999999;
int answer = INF;
typedef pair<int, int> pii; // .fisrt : r, .second : c
typedef pair<pii, pii> ppiipii;

vector<vector<int>> boards; // board
vector<pii> cards; // cards[i] : i번째 카드
map<pii, pii> mapper; // mapper[pii] : 해당 pii의 짝

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

// cur부터 1번 입력으로 이동 가능한 list return
vector<pii> getMoveablePoints(pii cur){
    vector<pii> result;
    // 상하좌우
    for(int i = 0; i<4; i++){
        int nr = cur.first + dr[i];
        int nc = cur.second + dc[i];
        if(0 <= nr && nr < boardsize && 0 <= nc && nc < boardsize){
            result.push_back({nr, nc});
        }
    }
    // ctrl + 상하좌우
    for(int i = 0; i<4; i++){
        int nr = cur.first, nc = cur.second;
        bool flag = false; // flag : 해당 방향으로 이동했을 때 열린 카드가 있는지
        do{
            nr += dr[i];
            nc += dc[i];
            // 만약 범위 벗어나면 break
            if(!(0 <= nr && nr < boardsize && 0 <= nc && nc < boardsize)){
                result.push_back({nr - dr[i], nc - dc[i]});
                break;
            }
            // 카드 있는 경우 해당 카드를 넣음
            if(boards[nr][nc] != 0){
                result.push_back({nr, nc});
                flag = true;
                break;
            }
        }while(0 <= nr && nr < boardsize && 0 <= nc && nc < boardsize);
    }
    return result;
}

// cur부터 모든 점까지 거리 리턴. BFS 이용
vector<vector<int>> get_dist(pii cur){
    vector<vector<int>> dist(boardsize, vector<int>(boardsize, INF)); // dist[r][c] : cur부터 {r, c}까지 거리
    vector<vector<bool>> visited(boardsize, vector<bool>(boardsize, false)); // visited[r][c] == true : 방문된 것
    queue<pair<pii, int>> q; // .first : 좌표, .second : cur부터 해당 좌표까지 거리
    
    q.push({cur, 0});
    dist[cur.first][cur.second] = 0;
    visited[cur.first][cur.second] = true;
    while(!q.empty()){
        pii top = q.front().first;
        int topdist = q.front().second;
        q.pop();
        
        // top으로부터 갈 수 있는 모든 것들 : 상하좌우, 상하좌우가장가까운카드 or 가장마지막칸
        vector<pii> moveables = getMoveablePoints(top); // 함수를 이용해 구함
        for(pii moveable : moveables){
            if(visited[moveable.first][moveable.second] == false){ // unvisited라면 해당 칸 탐색
                q.push({moveable, topdist + 1});
                visited[moveable.first][moveable.second] = true;
                dist[moveable.first][moveable.second] = topdist+1;
            }
                
        }
    }
    return dist;
}

void DFS(int cur_r, int cur_c, int cur_cnt, vector<bool> visited){
    if(answer < cur_cnt) return;
    int clear = true; // clear : 모든 open card가 closed인지 검사
    for(bool b : visited){
        if(b == false){
            clear = false;
            break;
        }
    }
    if(clear == true){ // clear라면 정답 갱신
        answer = min(answer, cur_cnt);
        return;
    }
    
    
    vector<vector<int>> dist_from_cur_to_all = get_dist({cur_r, cur_c}); // cur부터 모든 점까지 입력 개수
    for(int i = 0; i<visited.size(); i++){ // card로 backtrack
        if(visited[i] == false){ // unvisited인 것들에 대해 DFS
            // cards[i] : 현재 탐색할 카드
            pii paircard = mapper[{cards[i].first, cards[i].second}]; // card의 짝
            vector<vector<int>> dist_from_card_to_all = get_dist({cards[i].first, cards[i].second}); // card부터 모든 점까지 입력 개수
            int paircardidx = find(cards.begin(), cards.end(), paircard) - cards.begin(); // card 짝의 index
            
            visited[i] = visited[paircardidx] = true;
            int backup = boards[paircard.first][paircard.second];
            boards[cards[i].first][cards[i].second] = boards[paircard.first][paircard.second] = 0;
            // 다음 DFS할 때는 '현 위치 ~ cards[i]' + 'cards[i] ~ paircard(cards[i]의 pair)' + 2(엔터 2번)을 더해 주어야 함.
            DFS(paircard.first, paircard.second, cur_cnt + dist_from_cur_to_all[cards[i].first][cards[i].second] + dist_from_card_to_all[paircard.first][paircard.second] + 2, visited);
            visited[i] = visited[paircardidx] = false;
            boards[cards[i].first][cards[i].second] = boards[paircard.first][paircard.second] = backup;
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    boards = board;
    vector<vector<pii>> pairs(7); // pairs[i][0], pairs[i][1]은 서로 pair
    for(int r = 0; r<boardsize; r++){
        for(int c = 0; c<boardsize; c++){
            if(board[r][c] != 0){
                cards.push_back({r, c});
                pairs[board[r][c]].push_back({r, c});
            }
        }
    }
    vector<bool> visited(cards.size(), false); // visited[i] : true if ith card used
    for(vector<pii> v : pairs){
        if(v.size() == 0) continue;
        mapper[v[0]] = v[1];
        mapper[v[1]] = v[0];
    }
    
    DFS(r, c, 0, visited);
    
    return answer;
}

// 이것도 backtrack인 것 같은데...
// 모든 카드 위치 넣고 탐색 !