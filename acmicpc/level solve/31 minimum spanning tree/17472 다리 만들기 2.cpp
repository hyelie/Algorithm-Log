#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

/*
모든 섬을 set에 두고, 섬별 r좌표 min/max, c좌표 min/max 둠
*/

// 입출력 정보
int N, M;
vector<vector<int>> boards, visited;
int INF = 987654321;

// 섬 정보
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
vector<set<pii>> islands;
bool in_range(int r, int c){
    if(0 <= r && r < N && 0 <= c && c < M) return true;
    return false;
}
void DFS(int r, int c, int island_num){
    bool moveable = false;
    visited[r][c] = true;
    islands.back().insert({r, c});
    boards[r][c] = island_num;
    for(int d = 0; d<4; d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        // in range && ground && unvisited
        if(in_range(nr, nc) && boards[nr][nc] == 1 && visited[nr][nc] == false){
            moveable = true;
            DFS(nr, nc, island_num);
        }
    }

    if(!moveable){
        return;
    }
}

// bridge 정보
vector<vector<int>> edges;
void radial(int r, int c){ // r, c 기준으로 십자 방사
    int cur_island_num = boards[r][c];
    for(int d = 0; d<4; d++){
        int nr = r, nc = c;
        int cnt = -1;
        while(1){
            nr += dr[d]; nc += dc[d]; // move
            cnt++;
            if(!in_range(nr, nc)){ // if out of range, break
                break;
            }
            if(boards[nr][nc] == cur_island_num) break;
            else if(boards[nr][nc] != 0) { // find next island
                if(cnt < 2) break;
                edges[cur_island_num][boards[nr][nc]] = min(edges[cur_island_num][boards[nr][nc]], cnt);
                break;
            }
        }
    }
}

// mst 위한 함수
struct cmp{
    bool operator()(pii&a, pii&b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

void solve(){
    // get input
	cin>>N>>M;
    boards.resize(N, vector<int>(M));
    visited.resize(N, vector<int>(M, false));
    for(int r = 0; r<N; r++){
        for(int c = 0; c<M; c++){
            cin>>boards[r][c];
        }
    }

    // get island from input
    int num = 1;
    for(int r = 0; r<N; r++){
        for(int c = 0; c<M; c++){
            if(boards[r][c] == 1 && visited[r][c] == false){
                islands.push_back({});
                DFS(r, c, num);
                num++;
            }
        }
    }

    // 각 island의 다리
    edges.resize(islands.size()+1, vector<int>(islands.size()+1, INF));
    for(int i = 0; i<islands.size(); i++){ // for all island
        for(pii point : islands[i]){ // for all points in island
            radial(point.first, point.second); // 십자형 방사 전개
        }
    }

    // MST 구성 with prim
    set<int> mst;
    priority_queue<pii, vector<pii>, cmp> pq; // .first : index, second : weight
    int answer = 0;
    mst.insert(1);
    for (int i = 0; i <= islands.size(); i++){
        if (i == 0 || edges[1][i] == INF || edges[1][i] < 2) continue;
        pq.push({i, edges[1][i]});
    }
    while(!pq.empty() && mst.size() != islands.size()){
        int top = pq.top().first, weight = pq.top().second; pq.pop();
        if(weight < 2 || weight == INF) continue;
        if(mst.find(top) == mst.end()){ // not found in mst then push
            answer += weight;
            mst.insert(top);
            for(int i = 0; i<=islands.size(); i++){
                if(i == 0 || i == top || edges[top][i] == INF || edges[top][i] < 2) continue;
                pq.push({i, edges[top][i]});
            }
        }
    }

    if(mst.size() == islands.size()) cout<<answer;
    else cout<<-1;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}