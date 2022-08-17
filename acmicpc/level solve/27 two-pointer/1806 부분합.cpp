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
	ll N, S; cin>>N>>S;
	vector<ll> arr(N);
	for(int i= 0 ; i<N; i++) cin>>arr[i];

	ll INF = 987654321;
	ll s = 0, e = 0, cur_sum = 0, answer = INF;
	// cur_sum : s~e-1까지 합.
	while(e <= N){ // 따라서 부분합 설정을 e가 N까지 가게 해야 함.
		if(cur_sum >= S){
			answer = min(answer, e-s);
			cur_sum -= arr[s]; s++;
		}
		if(cur_sum < S){
			if(e == N) break;
			cur_sum += arr[e]; e++;
		}
	}
	cout<<(answer == INF ? 0 : answer);
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}