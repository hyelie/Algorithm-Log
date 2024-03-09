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

typedef long long ll;

ll N;
ll board[101][101], dp[101][101];
ll dr[2] = {1, 0};
ll dc[2] = {0, 1};
ll UNVISITED = -1;

ll recurse(ll r, ll c){ // r, c 위치에서 경로의 최소 수
    if(r == N-1 && c == N-1) return 1;
    if(dp[r][c] != UNVISITED) return dp[r][c];

    ll count = 0;
    for(ll k = 0; k<2; k++){
        ll nr = r + dr[k] * board[r][c];
        ll nc = c + dc[k] * board[r][c];
        if(0 <= nr && nr < N && 0 <= nc && nc < N){
            if(nr != N-1 && nc != N-1 && board[nr][nc] == 0) continue;
            count += recurse(nr, nc);
        }
    }
    dp[r][c] = count;
    return count;
}

void solve(){
    // input

	cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
            dp[i][j] = UNVISITED;
        }
    }

    // cal
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