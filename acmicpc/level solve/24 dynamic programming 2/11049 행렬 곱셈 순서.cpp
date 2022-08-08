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

int INF = 999999999;

void solve(){
	int N; cin>>N;
	vector<pii> msize(N);
	for(int i = 0; i<N; i++){
		cin>>msize[i].first>>msize[i].second;
	}

	// dp initialize
	vector<vector<int>> dp(N, vector<int>(N, 0)); // dp[i][j] : i~j의 행렬곱의 min value
	/*for(int i = 0; i<N-1; i++){
		dp[i][i+1] = msize[i].first * msize[i].second * msize[i+1].second;
	}*/ // 이 문제에 한해, 초기화 할 필요가 없다
	for(int diag = 1; diag<N; diag++){ // 대각선 개수
		for(int r = 0; r<N-diag; r++){ // row
			dp[r][r+diag] = INF;
			for(int m = 0; m<diag; m++){ // mid
				dp[r][r+diag] = min(dp[r][r+diag], dp[r][r+m] + dp[r+m+1][r+diag] + msize[r].first * msize[r+m+1].first * msize[r+diag].second);
			}
		}
	}

	cout<<dp[0][N-1]<<'\n';

	/*
	dp[i][j] = min{dp[i][i] + dp[i+1][j], dp[i][i+1] + dp[i+2][j], ... , dp[i][j-1] + dp[j][j]}
	dp[i][j] = {dp[i][m] + dp[m+1][j] + msize[i].first * msize[m].second * msize[j].second} 중 min
	*/
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