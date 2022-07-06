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
	vector<int> arr(n);

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}


	int NINF = -2000000000;
	vector<int> dp(n);
	dp[0] = arr[0];
	int num_update = 0;
	for(int i = 1; i<n; i++){
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
	}

	cout<<*max_element(dp.begin(), dp.end());



	//////////////////////

	return 0;
}