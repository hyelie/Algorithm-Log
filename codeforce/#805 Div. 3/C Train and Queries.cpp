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

string yes = "YES\n", no = "NO\n";

void solve(){
	int n, k; cin>>n>>k;
	map<int, vector<int>> m; // m[i] : station i가 있는 index vector
	int station; 
	for(int i = 0; i<n; i++){
		cin>>station;
		m[station].push_back(i);
	}
	for(auto &[key, value] : m){
		sort(value.begin(), value.end(), less<int>());
	}

	int a, b; // a : 시작, b : 도착
	string result;
	for(int i = 0; i<k; i++){
		cin>>a>>b;
		
		if(m[a].size() == 0 || m[b].size() == 0){
			result = no;
		}
		else if(upper_bound(m[b].begin(), m[b].end(), m[a][0]) == m[b].end()){
			result = no;
		}
		else result = yes;

		cout<<result;
	}

	// nlogn 이하
	// 지금은 map 썼는데, 좌표 압축을 써야 할지도. 아마 이게 맞는듯?
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