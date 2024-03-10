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
    // input
	int n; cin>>n;
    vector<int> arr(n), dp(n, 1);
    for(int i = 0; i<n; i++) cin>>arr[i];

    // solve 1. O(n*2)
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] < arr[j]){
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    cout<<*max_element(dp.begin(), dp.end());

    // solve 2. LIS
    dp.push_back(arr[0]);
    for(int i = 0; i<n; i++){
        if(dp.back() < arr[i]){
            dp.push_back(arr[i]);
        }
        else{
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    }

    cout<<dp.size();
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	// comment when submit
	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}