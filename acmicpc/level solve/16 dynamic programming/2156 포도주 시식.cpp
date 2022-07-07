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
	
	int n; cin>>n;
	vector<int> drinks(n+1), dp(n+1, 0);
	for(int i = 1; i<=n; i++) cin>>drinks[i];

	////////////// logic 1
	dp[1] = drinks[1];
	if(n >= 2) dp[2] = drinks[1] + drinks[2];
	if( n >= 3) dp[3] =max(drinks[3] + drinks[2], drinks[1] + drinks[3]);
	// dp[i] : i번째 잔을 마셨을 때 최대값

	for(int i = 4; i<=n; i++){
		dp[i] = max(max(dp[i-2] + drinks[i], dp[i-3] + drinks[i-1] + drinks[i]), dp[i-4] + drinks[i-1] + drinks[i]);
	}

	///////////// logic 2
	dp[1] = drinks[1];
	if(n >= 2) dp[2] = drinks[1] + drinks[2];
	// dp[i] : i번째 잔까지 봤을 때 최대값
	//		i번째를 마시지 않거나
	//		i-2번째 + i번째거나
	//		i-3번째 + i-1번째 + i번째거나

	for(int i = 3; i<=n; i++){
		dp[i] = max(max(dp[i-2] + drinks[i], dp[i-3] + drinks[i-1] + drinks[i]), dp[i-1]);
	}
	
	cout<<*max_element(dp.begin(), dp.end());

	//////////////////////

	return 0;
}