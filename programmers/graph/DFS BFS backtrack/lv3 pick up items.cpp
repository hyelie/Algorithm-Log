// 아이템 줍기

#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> board(101, vector<int>(101, 0)); // board[x][y] : character로부터 dist를 나타냄. -1은 unvisited
    // 직사각형들의 테두리 채우기
    for(vector<int> vi : rectangle){
        for(int x = 2 * vi[0]; x<=2 * vi[2]; x++){
            board[x][2 * vi[1]] = board[x][2 * vi[3]] = -1;
        }
        for(int y = 2 * vi[1]; y<=2 * vi[3]; y++){
            board[2 * vi[0]][y] = board[2 * vi[2]][y] = -1;
        }
    }
    // 직사각형 내부 비우기
    for(vector<int> vi : rectangle){
        for(int x = 2 * vi[0] + 1; x<=2 * vi[2] - 1; x++){
            for(int y = 2 * vi[1] + 1; y<=2 * vi[3] - 1; y++){
                board[x][y] = 0;
            }
        }
    }
    
    // pii.first : x, .second : y
    pii front, next;
    queue<pii> q; q.push({2 * characterX, 2 * characterY}); board[2 * characterX][2 * characterY] = 0;
    while(!q.empty()){
        front = q.front(); q.pop();
        if(front.first == 2 * itemX && front.second == 2 * itemY) return board[front.first][front.second] / 2;
        for(int i = 0; i<4; i++){
            next = {front.first + dx[i], front.second + dy[i]};
            if(0 <= next.first && next.first <= 100 && 0 <= next.second && next.second <= 100 && board[next.first][next.second] == -1){
                board[next.first][next.second] = board[front.first][front.second] + 1;
                q.push(next);
            }
        }
    }
    
    return 0;
}

// 오, 위, 왼, 아 순서로 DFS
// 그냥 BFS 하면 되지않나