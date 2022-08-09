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
	int n; cin>>n;
	vector<int> weights(n);
	for(int i = 0; i<n; i++){
		cin>>weights[i];
	}

	int target_n; cin>>target_n;
	vector<int> targets(target_n);
	for(int i = 0; i<target_n; i++){
		cin>>targets[i];
	}

	vector<vector<int>> dp(n, vector<int>(40001));
	// dp[i][j] : i번째 추까지 사용해서 무게 j를 측정할 수 있는지
	dp[0][weights[0]] = true;
	for(int i = 1; i<n; i++){
		dp[i][weights[i]] = true;
		for(int w = 0; w<=40000; w++){
			if(dp[i-1][w]){
				dp[i][w] = true;
				if(w + weights[i] <= 40000) dp[i][w+weights[i]] = true;
				if(w - weights[i] >= 0) dp[i][w-weights[i]] = true;
				if(weights[i] - w >= 0) dp[i][weights[i] - w] = true;
			}
		}
	}

	for(int targets : targets){
		if(dp[n-1][targets]) cout<<"Y ";
		else cout<<"N ";
	}
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