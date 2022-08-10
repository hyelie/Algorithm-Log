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

void solve(){
	int N, M; cin>>N>>M;
	vector<int> memories(N), costs(N);
	for(int &memory : memories) cin>>memory;
	for(int &cost : costs) cin>>cost;

	vector<vector<int>> dp(N+1, vector<int>(100*N+1, 0));
	// dp[i+1][j] : i번째까지 app, cost j을 사용해서 만들 수 있는 memory 최대값
	for(int a = 1; a<=N; a++){
		for(int c = 0; c<=100*N; c++){
			dp[a][c] = dp[a-1][c];
			if(c - costs[a-1] >= 0){
				dp[a][c] = max(dp[a][c], dp[a-1][c-costs[a-1]] + memories[a-1]);
			}
			// c - cost[a] >= 0 then dp[a-1][c-cost[a]] + memory[a]
		}
	}

	int min_cost = 99999999;
	for(int a = 1; a<=N; a++){
		for(int c = 0; c<=100*N; c++){
			if(dp[a][c] >= M) min_cost = min(min_cost, c);
		}
	}
	cout<<min_cost;
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