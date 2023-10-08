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

// GCD같다. 어떻게 하더라?

ll getGCD(ll a, ll b){
	ll r;
	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve(){
	int N; cin>>N;
	vector<ll> positions(N), gaps(N-1);
	for(int i = 0; i<N; i++) cin>>positions[i];
	for(int i = 1; i<N; i++) gaps[i-1] = positions[i] - positions[i-1];

	ll GCD = getGCD(gaps[0], gaps[1]);
	for(int i = 2; i<N-1; i++){
		GCD = getGCD(GCD, gaps[i]);
	}

	ll answer = 0;
	for(ll gap : gaps){
		answer += gap / GCD - 1;
	}
	cout<<answer;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}