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

ll gcd(int a, int b){
	ll r;
	if(b > a) return gcd(b, a);
	while(b != 0){
		r = (ll)a % b;
		a = b;
		b = r;
	}
	return a;
}

ll lcm(int a, int b){
	return (ll)a / gcd(a, b) * b;
}

bool isClear(vector<int>& num_cycle){
	for(int i : num_cycle) if(i == -1) return false;
	return true;
}

bool isRepeat(string s){
	int len = s.length();
	if(len&1) return false;
	if(s.substr(0, len/2) == s.substr(len/2, len/2)) return true;
	else return false;
}

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	vector<int> arr(n), num_cycle(n, -1);
	vector<string> strs(n, "");
	for(int i = 0; i<n; i++) cin>>arr[i];

	string origin_s = s, prev_s = s;
	while(!isClear(num_cycle)){
		for(int i = 0; i<n; i++){
			s[i] = prev_s[arr[i] - 1];
			if(num_cycle[i] == -1) strs[i] += s[i];
		}
		
		for(int i = 0; i<n; i++){
			if(num_cycle[i] == -1 && isRepeat(strs[i])){
				num_cycle[i] = strs[i].length()/2;
			}
		}
		prev_s = s;
	}

	ll result = num_cycle[0];
	for(int i = 1; i<n; i++){
		result = lcm(result, num_cycle[i]);
	}
	cout<<result<<'\n';
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