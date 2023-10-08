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

ll UNVISITED = -1;
vector<vector<ll>> dp(31, vector<ll>(31, UNVISITED));

// 1개짜리 full개와 반개짜리 half개가 있을 때 가능한 경우의 수
ll recurse(int full, int half){
	if(full == 0) return 1; // base : 1개짜리 없는 경우
	if(dp[full][half] != UNVISITED) return dp[full][half];

	// dp[full][half] = recurse(full-1, half+1) + recurse(full, half-1). 단, 후자는 0개 이상일때
	dp[full][half] = recurse(full-1, half+1);
	if(half >= 1) dp[full][half] += recurse(full, half-1);
	return dp[full][half];
}

void solve(int N){
	cout<<recurse(N, 0)<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	while(1){
		int N; cin>>N;
		if(N == 0) break;
		solve(N);
	}

	return 0;
}