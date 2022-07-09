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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n, k; cin>>n>>k;
	vector<int> coins(n);
	for(int i = 0; i<n; i++) cin>>coins[i];
	sort(coins.begin(), coins.end());

	int INF = 99999999;
	vector<vector<int>> dp(n, vector<int>(k+1, INF));
	// dp[i][j] : i번째까지 coin으로 j원 만들때 드는 최소 동전 개수
	for(int i = 0; coins[0] * i <= k; i++){
		dp[0][coins[0] * i] = i;
	}
	for(int i = 0; i<n; i++) dp[i][0] = 0;

	for(int i = 1; i<n; i++){
		for(int j = 1; j<=k; j++){
			dp[i][j] = dp[i-1][j];
			if(j >= coins[i])
				dp[i][j] = min(dp[i][j], dp[i][j-coins[i]] + 1);
		}
	}
	int answer = dp[n-1][k];
	if(answer == INF) answer = -1;
	
	cout<<answer;
	

	//////////////////////

	return 0;
}