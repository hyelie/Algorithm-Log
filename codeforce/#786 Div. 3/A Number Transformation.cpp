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

ll STANDARD = 1000000000;

void solve(){
	ll x, y; cin>>x>>y;
	// a, b를 골라서 x를 a번 곱함 b^a * x = y가 되는 a, b를 구하라
	if(y%x != 0){
		cout<<"0 0\n";
		return;
	}
	ll a = 1, b = y/x;
	cout<<a<<' '<<b<<'\n';

}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}