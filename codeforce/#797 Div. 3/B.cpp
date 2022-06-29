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
ll INF = 200000000000;

void solve(){
	int n; cin>>n;
	vector<ll> a(n), b(n);
 
	ll diff_min = INF;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	for(int i = 0; i<n; i++){
		cin>>b[i];
		if(b[i] != 0) diff_min = min(a[i] - b[i], diff_min);
	}
 
	for(int i = 0; i<n; i++){
		if(a[i] < b[i]){
			cout<<"NO\n";
			return;
		}
		if(a[i] - diff_min <= 0 || a[i] - diff_min == b[i]) continue;
		else{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}



	//////////////////////

	return 0;
}

/*
모든 원소의 차이를 diff라고 했을 때
i번째 원소가 정확하게 diff거나, a[i] - diff <= 0이어야 함
*/