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
    vector<pii> datas(N);
    for(int i = 0; i<N; i++){
        cin>>datas[i].first>>datas[i].second;
    }

    vector<int> dp(N, 0); // dp[i] : i번째날에 상담했을 때 최대값
    for(int i = N-1; i>=0; i--){
        if(datas[i].first + i >= N) continue;
        for(int j = i + datas[i].first; j<N; j++){
            dp[i] = max(dp[i] + datas[i].second, dp[j]);
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	// comment when submit
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}