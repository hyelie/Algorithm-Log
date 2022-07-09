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
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

void solve(){
	int n; cin>>n;
	vector<vector<int>> stickers(2, vector<int>(n));
	for(int i = 0; i<2; i++){
		for(int j = 0; j<n; j++){
			cin>>stickers[i][j];
		}
	}

	vector<vector<int>> dp(2, vector<int>(n, 0));
	// dp[i][j] : i번째 row, j번째 col의 sticker를 선택했을 때 최댓값
	dp[0][0] = stickers[0][0];
	dp[1][0] = stickers[1][0];
	if(n >= 2){
		dp[0][1] = dp[1][0] + stickers[0][1];
		dp[1][1] = dp[0][0] + stickers[1][1];
	}
	for(int c = 2; c<n; c++){
		// c-1의 것을 택할 것인지(그 경우, 대각에 있는 것)
		// c-2의 것을 택할 것인지(그 경우, c-1은 택하지 못함)
		dp[0][c] = max(dp[1][c-1], dp[1][c-2]) + stickers[0][c];
		dp[1][c] = max(dp[0][c-1], dp[0][c-2]) + stickers[1][c];
	}
	cout<<max(dp[0][n-1], dp[1][n-1])<<'\n';

	/*

	i, i+1, i+2번째 column에 대해
	1) i+1번째와 겹치지 않게 고르기
	2) i+1번째와 겹쳐서 dp[i] + max(stickers[0][i+2], stickers[1][i+2])
	중 max값

	*/
	return;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int T; cin>>T;
	while(T--) solve();

	//////////////////////

	return 0;
}