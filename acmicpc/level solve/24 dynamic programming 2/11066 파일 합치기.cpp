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

vector<int> files;
vector<int> psum;
int INF = 999999999;

int getRangesum(int i, int j){ // return prefix sum from i to j
	int f = (i == 0 ? 0 : psum[i-1]);
	return psum[j] - f;
}

void solve(){
	int K; cin>>K;
	files.resize(K);
	psum.resize(K);
	for(int i = 0; i<K; i++){
		cin>>files[i];
		psum[i] = files[i];
		if(i != 0){
			psum[i] += psum[i-1];
		}
	}

	// dp initialize
	vector<vector<int>> dp(K, vector<int>(K, 0));
	for(int r = 0; r<K-1; r++){
		dp[r][r+1] = files[r] + files[r+1];
	}

	// do dp
	for(int diff = 2; diff<K; diff++){ // 대각선 개수 (총 K개, [i][i]와 [i][i+1]은 이미 했으니 K-2개를 해야 함)
		for(int r = 0; r<K-diff; r++){ // row 개수 (총 K개에서 대각선 개수만큼 빼야 함)
			dp[r][r+diff] = INF;
			for(int mid = 0; mid<diff; mid++){ // colmun 선택 가능한 개수 == 대각선 개후
				dp[r][r+diff] = min(dp[r][r+diff], dp[r][r+mid] + dp[r+mid+1][r+diff]);
			}
			dp[r][r+diff] += getRangesum(r, r+diff);
		}
	}

	cout<<dp[0][K-1]<<'\n';

	/*
	dp[i][j] : index i부터 index j까지 합치는 데 필요한 cost
	두 파일을 합칠 때 필요한 cost = 두 파일 크기의 합
	dp[i][i] = 0
	dp[i][i+1] = files[i] + files[i+1]
	dp[i][i+2] = min{dp[i][i] + dp[i+1][i+2], dp[i][i+1] + dp[i+2][i+2]}(cost가 최소인 두 파일 선택) + psum(i, i+2) (두 파일 크기의 합)
	...
	dp[i][j] = min{dp[i][i] + dp[i+1][j], dp[i][i+1] + dp[i+2][j], ... , dp[i][j-1] + dp[j][j]} + psum(i, j)

	정리하자면 dp[i][j] = dp[i][m] + dp[m+1][j] + ['i~m의 file sum' + 'm+1~j의 file sum']이다.
	이 때 m이 어떤 값이듯 뒷항은 동일, 따라서 앞 항을 최소화하는 m을 찾기만 하면 된다.
	*/
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}