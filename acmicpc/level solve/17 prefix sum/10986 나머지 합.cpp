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
	
	ll N, M; cin>>N>>M;
	vector<ll> arr(N);
	for(ll i = 0; i<N; i++) cin>>arr[i];

	vector<ll> psum(N);
	vector<ll> cnt(M, 0);
	psum[0] = arr[0] % M;
	cnt[psum[0]]++;
	for(ll i = 1; i<N; i++){
		psum[i] = (psum[i-1] + arr[i]) % M;
		cnt[psum[i]]++;
	}

	ll answer = 0;
	for(ll i = 0; i<M; i++){
		answer += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout<<answer + cnt[0];

	//////////////////////

	return 0;
}