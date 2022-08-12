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

int M, N, K;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};


void dfs(int r, int c, vector<vector<bool>>& board, vector<vector<bool>>& visited){
	visited[r][c] = true;

	for(int i = 0; i<4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(0 <= nr && nr < M && 0 <= nc && nc < N && !visited[nr][nc] && board[nr][nc]){
			visited[nr][nc] = true;
			dfs(nr, nc, board, visited);
		}
	}
}

void solve(){
	cin>>M>>N>>K;
	vector<vector<bool>> board(M, (vector<bool>(N, false)));
	vector<vector<bool>> visited(M, (vector<bool>(N, false)));
	int r, c;
	while(K--){
		cin>>r>>c;
		board[r][c] = true;
	}

	int cnt = 0;
	for(int i = 0; i<M; i++){
		for(int j = 0; j<N; j++){
			if(!visited[i][j] && board[i][j]){
				dfs(i, j, board, visited);
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}