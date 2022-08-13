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

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void solve(){
	int INF = 100000000;
	int N, M; cin>>N>>M;
	vector<string> grid(N);
	vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2, INF)));
	dist[0][0][0] = dist[0][0][1] = 1;
	// dist[r][c][0] : dist from [0, 0] to [r, c], 벽 부수지 않음
	// dist[r][c][1] : dist from [0, 0] to [r, c], 벽 부숨
	for(string &str : grid) cin>>str;

	queue<pair<pii, bool>> q; q.push({{0, 0}, false}); // .first : 좌표. second :부순 여부
	while(!q.empty()){
		pii cur = q.front().first;
		bool didBroke = q.front().second;
		int cr = cur.first;
		int cc = cur.second;
		if(cr == N-1 && cc == M-1) break;
		q.pop();
		for(int d = 0; d<4; d++){
			int nr = cr + dr[d];
			int nc = cc + dc[d];
			if(0 <= nr && nr < N && 0 <= nc && nc < M){
				if(grid[nr][nc] == '0' && dist[nr][nc][didBroke] == INF){
					q.push({{nr, nc}, didBroke}); // 안부수고 진행
					dist[nr][nc][didBroke] = dist[cr][cc][didBroke] + 1;
				}
				if(!didBroke && grid[nr][nc] == '1' && dist[nr][nc][1] == INF){
					q.push({{nr, nc}, true}); // 안부셨다면 부실 수 있음
					dist[nr][nc][1] = dist[cr][cc][didBroke] + 1;
				}
			}
		}
	}
	int answer = min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
	answer = (answer == INF ? -1 : answer);
	cout<<answer;
}

/*
벽을 부쉈다면(didBroke가 true) false로 넘어갈 수 없음
벽을 부수지 않았다면 (false라면) true로 갈 수도 있고 false를 유지할 수도 있음
*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}