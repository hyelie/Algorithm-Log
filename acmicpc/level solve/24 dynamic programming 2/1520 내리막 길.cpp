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

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int board[501][501], dp[501][501];
int M, N;

int search(int r, int c){
	if(r == M-1 && c == N-1) return 1;
	if(dp[r][c] != -1) return dp[r][c];
	dp[r][c] = 0;
	for(int d = 0; d<4; d++){
		int nr = r + dr[d];
		int nc = c + dc[d];
		if(0 <= nr && nr < M && 0 <= nc && nc < N && board[r][c] > board[nr][nc]){
			dp[r][c] += search(nr, nc);
		}
	}
	return dp[r][c];
}

void solve(){
	cin>>M>>N;
	for(int r = 0; r<M; r++){
		for(int c = 0; c<N; c++){
			cin>>board[r][c];
			dp[r][c] = -1;
		}
	}
	cout<<search(0, 0)<<'\n';


}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	solve();
	

	//////////////////////

	return 0;
}