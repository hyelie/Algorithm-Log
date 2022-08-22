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
	vector<int> arr(N);
	for(int i = 0; i<N; i++){
		cin>>arr[i];
	}

	vector<int> LIS(1), dp(N);
	LIS[0] = arr[0]; dp[0] = 1;
	for(int i = 1; i<N; i++){
		if(LIS.back() < arr[i]){
			LIS.push_back(arr[i]);
			dp[i] = LIS.size();
		}
		else{
			int idx = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
			LIS[idx] = arr[i];
			dp[i] = idx+1;
		}
	}

	cout<<LIS.size()<<'\n';
	for(int i = N-1, cnt=LIS.size(); i>=0; i--){
		if(dp[i] == cnt){
			cnt--;
			LIS[cnt] = arr[i];
		}
	}
	for(int elem : LIS) cout<<elem<<' ';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}