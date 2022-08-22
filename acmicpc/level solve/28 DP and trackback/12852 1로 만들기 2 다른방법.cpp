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
	vector<int> prev(N+1); 

	dp[0] = 1; dp[1] = 0;
	for(int i = 2; i<=N; i++){
		dp[i] = dp[i-1] + 1;
		prev[i] = i-1;

		if(i%2 == 0){
			if(dp[i] > dp[i/2] + 1){
				dp[i] = dp[i/2] + 1;
				prev[i] = i/2;
			}
		}
		if(i%3 == 0){
			if(dp[i] > dp[i/3] + 1){
				dp[i] = dp[i/3] + 1;
				prev[i] = i/3;
			}
		}
	}
	cout<<dp[N]<<'\n';
	while(N != 0){
		cout<<N<<' ';
		N = prev[N];
	}
}

// 역추적 특 : {dp[i] = ...} 점화식 세우고 답부터 찾아가면 됨. 말 그대로 역추적.
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