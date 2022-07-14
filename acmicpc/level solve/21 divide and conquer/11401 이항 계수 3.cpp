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
	
	ll N, K; cin>>N>>K;
	ll MOD = 1000000007;

	ll A = 1;
	for(ll i = N; i>=N-K+1; i--){
		A = (A * i) % MOD;
	}

	ll KF = 1;
	for(ll i = 1; i<=K; i++){
		KF = (KF * i) % MOD;
	}

	ll factor = MOD - 2, B = 1;
	while(factor != 0){
		if(factor & 1){
			B = (B * KF) % MOD;
		}
		KF = (KF * KF) % MOD;
		factor >>= 1;
	}

	cout<<(A * B) % MOD;

	//////////////////////

	return 0;
}