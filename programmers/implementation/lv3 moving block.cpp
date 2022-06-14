// 블록 이동하기

#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

int N;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii; //drone 위치

bool cmp(pii &a, pii &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void sort_ppiipii(ppiipii &a){
    if(!cmp(a.first, a.second)){
        pii temp = a.first;
        a.first = a.second;
        a.second = temp;
        return;
    }
    return;
}

void rotate(vector<vector<int>>& board, pii mov, pii axis, bool isVertical, vector<ppiipii>& result){
    if(isVertical){ // 세로
        if(axis.second + 1 < N && board[mov.first][axis.second+1] == 0 && board[axis.first][axis.second + 1] == 0){
            result.push_back({axis, {axis.first, axis.second + 1}});
        }
        if(axis.second - 1 >= 0 && board[mov.first][axis.second-1] == 0 && board[axis.first][axis.second - 1] == 0){
            result.push_back({axis, {axis.first, axis.second - 1}});
        }
    }
    else{ // 가로
        if(axis.first + 1 < N && board[axis.first + 1][mov.second] == 0 && board[axis.first + 1][axis.second] == 0){
            result.push_back({axis, {axis.first + 1, axis.second}});
        }
        if(axis.first - 1 >= 0 && board[axis.first - 1][mov.second] == 0 && board[axis.first - 1][axis.second] == 0){
            result.push_back({axis, {axis.first - 1, axis.second}});
        }
    }
}
/*
 가로 : (r, c)와 (r', c')에서 축이 (r, c)인 경우
            (r+1, c)와 (r-1, c)로 갈 수 있음
            (r+1, c)로 가는 경우 : (r+1, c')가 1인지 검사해야 함
            (r-1, c)로 가는 셩우 : (r-1, c')가 1인지 검사해야 함
 세로 : (r, c)와 (r', c')에서 축이 (r, c)인 경우
            (r, c+1)와 (r, c-1)로 갈 수 있음
            (r, c+1)로 가는 경우 : (r', c+1)가 1인지 검사해야 함
            (r, c-1)로 가는 경우 : (r', c-1)가 1인지 검사해야 함*/

vector<ppiipii> moveablePosition(vector<vector<int>>& board, ppiipii &cur_position){
    vector<ppiipii> result;
    pii blue = cur_position.first, red = cur_position.second;
    if(blue.first + 1 < N && board[blue.first + 1][blue.second] == 0 && red.first + 1 < N && board[red.first + 1][red.second] == 0){ // 하
        result.push_back({{blue.first+1, blue.second}, {red.first+1, red.second}});
    }
    if(blue.first - 1 >= 0 && board[blue.first - 1][blue.second] == 0 && red.first - 1 >= 0 && board[red.first - 1][red.second] == 0){ // 상
        result.push_back({{blue.first-1, blue.second}, {red.first-1, red.second}});
    }
    if(blue.second + 1 < N && board[blue.first][blue.second + 1] == 0 && red.second + 1 < N && board[red.first][red.second + 1] == 0){ // 우
        result.push_back({{blue.first, blue.second + 1}, {red.first, red.second + 1}});
    }
    if(blue.second - 1 >= 0 && board[blue.first][blue.second - 1] == 0 && red.second - 1 >= 0 && board[red.first][red.second - 1] == 0){ // 좌
        result.push_back({{blue.first, blue.second - 1}, {red.first, red.second - 1}});
    }
    
    bool isVertical = blue.second == red.second;
    rotate(board, blue, red, isVertical, result);
    rotate(board, red, blue, isVertical, result);
    for(int i = 0; i<result.size(); i++){
        sort_ppiipii(result[i]);
    }
    return result;
}

bool isArrive(ppiipii& cur_position){
    pii blue = cur_position.first, red = cur_position.second;
    if((blue.first == N-1 && blue.second == N-1) || (red.first == N-1 && red.second == N-1)) return true;
    else return false;
}

int solution(vector<vector<int>> board) {
    N = board.size();
    
    ppiipii drone = {{0, 0}, {0, 1}}; // .first : 첫 번째 점, .second : 두 번째 점
    
    set<ppiipii> visited;
    sort_ppiipii(drone);
    visited.insert(drone);
    
    queue<pair<ppiipii, int>> q; // .first : 현재 드론 위치 ppiipii, .second : 해당 위치의 dist
    q.push({drone, 0});
    
    while(!q.empty()){
        ppiipii cur_position = q.front().first;
        int cur_dist = q.front().second;
        
        /*cout<<"점, dist : "<<cur_dist<<endl;
        cout<<"blue : "<<cur_position.first.first<<", "<<cur_position.first.second<<endl;
        cout<<"red : "<<cur_position.second.first<<", "<<cur_position.second.second<<endl;
        cout<<endl;*/
        
        q.pop();
        vector<ppiipii> moveable = moveablePosition(board, cur_position);
        for(ppiipii& m : moveable){
            
            if(isArrive(m)){
                return cur_dist + 1;
            }
            
            sort_ppiipii(m);
            
            if(visited.find(m) == visited.end()){ // not visited
                visited.insert(m);
                q.push({m, cur_dist + 1});
            }
        }
    }
    return -1;
}

/*

BFS인데 신경 쓸 게 많은...
1) visited 배열 - 현재 로봇의 위치는 점 2개로 이루어지니 이들의 중복 검사를 할 수 있게 해야 함
2) 이동하는 경로 - 현재 위치 (r, c), (r', c') 기준으로 어디로 이동할 수 있는가?
  a) 직선 이동하는 경우 - 위 / 아 / 왼 / 오 - 모두 다 범위 안이고 0이어야 이동할 수 있음
  b) 회전 이동하는 경우 - (r, c)을 축으로 90도

 가로 : (r, c)와 (r', c')에서 축이 (r, c)인 경우
            (r+1, c)와 (r-1, c)로 갈 수 있음
            (r+1, c)로 가는 경우 : (r+1, c')가 1인지 검사해야 함
            (r-1, c)로 가는 셩우 : (r-1, c')가 1인지 검사해야 함
 세로 : (r, c)에서 (r', c')인 경우
            (r, c+1)와 (r, c-1)로 갈 수 있음
            (r, c+1)로 가는 경우 : (r', c+1)가 1인지 검사해야 함
            (r, c-1)로 가는 경우 : (r', c-1)가 1인지 검사해야 함
            
그러면 이동의 경우의 수 : 축 1개당 2개고 축 2개니 4개, 상하좌우 4개, 계 8개

*/