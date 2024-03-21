#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct pos{    
    int r1, c1, r2, c2;
};

typedef pair<pos, int> ppi;

struct cmp{
    bool operator() (const pos &a, const pos &b) const{
        if(a.r1 == b.r1) return a.c2 < b.c2;
        return a.r1 < b.r1;
    }
};

int n;
set<pos, cmp> visited;

void mark_visited(pos p){
    pos swap_p = {p.r2, p.c2, p.r1, p.c1};
    visited.insert(p);
    visited.insert(swap_p);
}

bool is_visited(pos p){
    return visited.find(p) != visited.end();
}

bool is_destination(pos p){
    if(p.r1 == n-1 && p.c1 == n-1) return true;
    if(p.r2 == n-1 && p.c2 == n-1) return true;
    return false;
}

bool is_in(pos p){
    if(0 <= p.r1 && p.r1 < n
      && 0 <= p.c1 && p.c1 < n
      && 0 <= p.r2 && p.r2 < n
      && 0 <= p.c2 && p.c2 < n) return true;
    return false;
}

pos copy_pos(pos cur){
    return {cur.r1, cur.c1, cur.r2, cur.c2};
}

void sort_pos(pos &cur){ // 항상 좌상단에 있는 게 먼저 오게
    if(cur.c1 > cur.c2){
        int temp = cur.c1;
        cur.c1 = cur.c2;
        cur.c2 = temp;
    }
    if(cur.r1 > cur.r2){
        int temp = cur.r1;
        cur.r1 = cur.r2;
        cur.r2 = temp;
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    queue<ppi> q;
    q.push({{0, 0, 0, 1}, 0});
    mark_visited({0, 0, 0, 1});
    
    while(!q.empty()){
        pos cur = q.front().first; 
        sort_pos(cur);
        int cur_dist = q.front().second;
        q.pop();
        
        if(is_destination(cur)) return cur_dist;
        
        // 이동할 수 있는 모든 위치
        pos temp;
        // 위
        temp = copy_pos(cur);
        temp.r1--; temp.r2--; sort_pos(temp);
        if(is_in(temp) && !is_visited(temp)){
            mark_visited(temp);
            q.push({temp, cur_dist + 1});
        }
        
        // 아래
        temp = copy_pos(cur);
        temp.r1++; temp.r2++; sort_pos(temp);
        if(is_in(temp) && !is_visited(temp)){
            mark_visited(temp);
            q.push({temp, cur_dist + 1});
        }
        
        // 오른쪽
        temp = copy_pos(cur);
        temp.c1++; temp.c2++; sort_pos(temp);
        if(is_in(temp) && !is_visited(temp)){
            mark_visited(temp);
            q.push({temp, cur_dist + 1});
        }
        
        // 왼쪽
        temp = copy_pos(cur);
        temp.c1--; temp.c1--; sort_pos(temp);
        if(is_in(temp) && !is_visited(temp)){
            mark_visited(temp);
            q.push({temp, cur_dist + 1});
        }
        
        // 가로로 눕혀진 경우
        if(cur.r1 == cur.r2){
            temp = copy_pos(cur);
            temp.r2 = temp.r1-1; temp.c2 = temp.c1;
            if(is_in(temp) && board[temp.r1-1][temp.c1+1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
            
            temp = copy_pos(cur);
            temp.r1 = temp.r2; temp.c1 = temp.c2;
            if(is_in(temp) && board[temp.r2-1][temp.c2-1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
            
            temp = copy_pos(cur);
            temp.r2 = temp.r1+1; temp.c2 = temp.c1;
            if(is_in(temp) && board[temp.r1+1][temp.c1+1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
            
            temp = copy_pos(cur);
            temp.r1 = temp.r2; temp.c1 = temp.c2;
            if(is_in(temp) && board[temp.r2+1][temp.c2-1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
        }
        
        // 세로로 세워진 경우
        else{
            temp = copy_pos(cur);
            temp.r2 = temp.r1; temp.c2 = temp.c1-1;
            if(is_in(temp) && board[temp.r1+1][temp.c1-1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
            
            temp = copy_pos(cur);
            temp.r1 = temp.r2; temp.c1 = temp.c2-1;
            if(is_in(temp) && board[temp.r2-1][temp.c2-1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
            
            temp = copy_pos(cur);
            temp.r2 = temp.r1; temp.c2 = temp.c1+1;
            if(is_in(temp) && board[temp.r1+1][temp.c1+1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
            
            temp = copy_pos(cur);
            temp.r1 = temp.r2; temp.c1 = temp.c2+1;
            if(is_in(temp) && board[temp.r2-1][temp.c2+1] == 0 && !is_visited(temp)){
                sort_pos(temp);
                mark_visited(temp);
                q.push({temp, cur_dist + 1});
            }
        }
    }
    
    return -1;
}