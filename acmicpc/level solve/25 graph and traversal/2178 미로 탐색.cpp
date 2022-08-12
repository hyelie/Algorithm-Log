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

int N, M;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void solve(){
	cin>>N>>M;
	vector<string> board(N);
	vector<vector<int>> dist(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	for(string &s : board) cin>>s;
	
	queue<pii> q;
	q.push({0, 0});
	visited[0][0] = true;
	dist[0][0] = 1;
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		if(cur.first == N-1 && cur.second == M-1){
			cout<<dist[cur.first][cur.second]<<'\n';
			return;
		}
		for(int d = 0; d<4; d++){
			pii next = {cur.first + dr[d], cur.second + dc[d]};
			if(0 <= next.first && next.first < N && 0 <= next.second && next.second < M && board[next.first][next.second] == '1' && !visited[next.first][next.second]){
				q.push(next);
				visited[next.first][next.second] = true;
				dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
			}
		}
	}
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}