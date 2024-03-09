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

int M, N;
int INF = -1;
int board[501][501], dp[501][501];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int recurse(int i, int j){ // i, j에서 M-1, N-1로 가는 경로 개수
    if(i == M-1 && j == N-1) return 1;
    if(dp[i][j] != INF) return dp[i][j];
    
    int count = 0;
    for(int k = 0; k<4; k++){
        int nr = i + dr[k];
        int nc = j + dc[k];
        if(0 <= nr && nr < M && 0 <= nc && nc < N && board[i][j] > board[nr][nc]){
            count += recurse(nr, nc);
        }
    }
    dp[i][j] = count;
    return dp[i][j];
}

void solve(){
    // input
	cin>>M>>N;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
            dp[i][j] = INF;
        }
    }

    // dp
    board[M-1][N-1] = 1;
    cout<<recurse(0, 0)<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	// comment when submit
	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}