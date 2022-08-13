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
	int M, N; cin>>M>>N;
	vector<vector<int>> board(N, vector<int>(M)), date(N, vector<int>(M, 0));
	queue<pii> q;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			cin>>board[i][j];
			if(board[i][j] == 1){
				q.push({i, j});
			}
		}
	}

	while(!q.empty()){
		pii cur = q.front(); q.pop();
		for(int d = 0; d<4; d++){
			int nr = cur.first + dr[d];
			int nc = cur.second + dc[d];
			if(0 <= nr && nr < N && 0 <= nc && nc < M && board[nr][nc] == 0){
				date[nr][nc] = date[cur.first][cur.second] + 1;
				board[nr][nc] = 1;
				q.push({nr, nc});
			}
		}
	}

	int max_date = -1;
	for(int i = 0; i<N; i++){t
		for(int j =0; j<M; j++){
			if(board[i][j] == 0){
				cout<<"-1";
				return;
			}
			max_date = max(max_date, date[i][j]);
		}
	}
	cout<<max_date;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}