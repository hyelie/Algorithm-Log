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

void solve(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i = n-1; i>=0; i--) cin>>arr[i];

	// sequence의 모든 숫자가 distinct

	// 모든 수의 개수가 1 이하로 맞춰질 때 까지 첫 자를 지움
	// 뒤에서부터 세서 개수가 2인 원소가 발견되는 즉시 멈추고 그 index부터 따짐
	map<int, int> m;

	int i;
	for(i = 0; i<n; i++){
		if(m.find(arr[i]) == m.end()){ // not exist in map
			m[arr[i]] = 1;
		}
		else{ // exist in map
			break;
		}
	}
	cout<<n-i<<'\n';
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