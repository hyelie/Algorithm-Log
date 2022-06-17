// 사라지는 발판

#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int max_r, max_c;
vector<vector<int>> boards;
vector<pii> players;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector<pii> moves(10);

vector<pii> getMoveablePoints(pii cur_p){
    vector<pii> result;
    for(int i = 0; i<4; i++){
        pii next_p;
        next_p.first = cur_p.first + dr[i];
        next_p.second = cur_p.second + dc[i];
        if(0 <= next_p.first && next_p.first < max_r && 0 <= next_p.second && next_p.second < max_c && boards[next_p.first][next_p.second] == 1){
            result.push_back(next_p);
        }
    }
    return result;
}

// return .first : 승자, .second : 끝날 때 까지 남은 턴 수
pii backtrack(int isA){ // isA가 0이면 A, 1이면 B
    pii &player = players[isA]; // 현재 움직일 player
    pii player_backup = players[isA];
    
    vector<pii> moveable_points = getMoveablePoints(player);
    if(boards[player.first][player.second] == 0 || moveable_points.size() == 0){ // 못 움직이면 끝임.
        return {1 - isA, 0}; // 못 움직인다면 자신이 아닌 플레이어의 승. 남은 턴 수 == 0
    }
    
    
    int max_turn = -1, min_turn = 99999, canWin = -1; // canwin == 승리자
    for(pii mp : moveable_points){
        player = mp;
        boards[player_backup.first][player_backup.second] = 0;
        pii result = backtrack(1 - isA);
        int winner = result.first; // 0이면 A 승, 1이면 B 승
        int left_turn = result.second;
        player = player_backup;
        boards[player_backup.first][player_backup.second] = 1;
        
        // 핵심 로직
        if(winner == isA){ // 현 플레이어가 승리할 수 있으면
            canWin = isA; // 승리자는 현 플레이어
            min_turn = min(min_turn, left_turn); // 최대한 수를 짧게 가지고 간다.
        } else{
            if(canWin == isA) continue; // 승리할 수 있는 수가 있는데 패배하는 수를 고를 경우 continue
            canWin = 1 - isA; // 패배하는 경우의 수
            max_turn = max(max_turn, left_turn); // 최대한 길게 끌고 간다.
        }
    }

    return {canWin, (canWin == isA ? min_turn : max_turn) + 1};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    max_r = board.size();
    max_c = board[0].size();
    boards = board;
    
    players.push_back({aloc[0], aloc[1]});
    players.push_back({bloc[0], bloc[1]}); // players[0] : A, 1 : B
    
    return backtrack(0).second;
}