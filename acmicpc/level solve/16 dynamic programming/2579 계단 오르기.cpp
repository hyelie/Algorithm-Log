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

void solve(){
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	vector<int> stairs(n), dp(n, 0); // dp[i] : i번째 계단을 밟았을 때 최대값
	for(int i = 0; i<n; i++) cin>>stairs[i];

	dp[0] = stairs[0];
	if(n>=2) dp[1] = stairs[0] + stairs[1];
	if(n>=3) dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
	for(int i = 3; i<n; i++){
		dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
	}
	cout<<dp[n-1];


	//////////////////////

	return 0;
}