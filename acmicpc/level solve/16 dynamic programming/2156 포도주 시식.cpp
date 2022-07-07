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
	vector<int> drinks(n), dp(n, 0);
	for(int i = 0; i<n; i++) cin>>drinks[i];

	dp[0] = drinks[0];
	if(n >= 2) dp[1] = drinks[0] + drinks[1];
	if(n >= 3) dp[2] = max(dp[1], max(drinks[0] + drinks[1], drinks[0] + drinks[2]));
	// dp[i] : i번째 잔을 마셨을 때 최대값

	for(int i = 3; i<n; i++){
		dp[i] = max(dp[i-2] + drinks[i], dp[i-3] + drinks[i-1] + drinks[i]);
	}
	
	cout<<*max_element(dp.begin(), dp.end());

	//////////////////////

	return 0;
}