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
	int n, k; cin>>n>>k;
	vector<int> coins(n);
	for(int &coin : coins) cin>>coin;
	sort(coins.begin(), coins.end(), less<int>());

	vector<int> dp(k+1, 0); dp[0] = 1;

	// dp[k] : k원 만드는 경우의 수
	// 점화식 : dp[i] = dp[i] + dp[i - coin[j]];
	for(int idx = 0; idx<n; idx++){
		for(int value = 0; value <= k; value++){
			int temp = value - coins[idx];
			if(temp >= 0) dp[value] += dp[temp];
		}
	}
	

	cout<<dp[k];
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

/*
2 5 10
2 2 2 2 2
5 5
2개

1 2 3 4 5 6 7 8 9 10
1 1 1 1 1 1 1 1 1 1 
1 2 2 3 3 4 4 5 5 6
1 2 2 3 4 5 6 7 8 10

dp[i] + dp[i-coin]


*/