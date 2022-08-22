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

void solve(){
	int N; cin>>N;
	int INF = 987654321;
	vector<int> dp(N+1, INF); 

	dp[0] = 1; dp[1] = 0;
	for(int i = 1; i<=N; i++){
		if(i+1 <= N){
			dp[i+1] = min(dp[i+1], dp[i]+1);
		}
		if(i*2 <= N){
			dp[i*2] = min(dp[i*2], dp[i]+1);
		}
		if(i*3 <= N){
			dp[i*3] = min(dp[i*3], dp[i]+1);
		}
	}
	cout<<dp[N]<<'\n';
	for(int i = N, cnt = dp[N], prev = N+1; i>=0; i--){
		if(dp[i] == cnt && (prev - 1 == i || i*2 == prev || i*3 == prev)){
			cout<<i<<' ';
			cnt--;
			prev = i;
		}
	}
}

// 역추적 특 : 답부터 찾아가면 됨
/*
	dp[i+1] = dp[i] + 1
	dp[2i] = dp[i] + 1
	dp[3i] = dp[i] + 1
*/

//////////////////////

int main(void) {
	// cin.tie(0);
	// cout.tie(0);
	// std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}