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
typedef pair<ll, ll> pll;

pll decompose(int n){
	ll t = 2, f = 5;
	ll num_t = 0, num_f = 0;

	while(n/t > 0){
		num_t += n/t;
		t *= 2;
	}
	while(n/f > 0){
		num_f += n/f;
		f *= 5;
	}
	return {num_t, num_f};
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n, m; cin>>n>>m;
	pll nc = decompose(n);
	pll ml = decompose(m);
	pll mr = decompose(n-m);

	cout<<min(nc.first - ml.first - mr.first, nc.second - ml.second - mr.second);
	
	

	//////////////////////

	return 0;
}