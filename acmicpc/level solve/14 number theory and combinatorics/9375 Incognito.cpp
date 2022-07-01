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
	int n; cin>>n;
	string name, category;
	map<string, set<string>> m;
	while(n--){
		cin>>name>>category;
		m[category].insert(name);
	}

	int result = 1;
	for(auto& [key, value] : m){
		result *= ((int)value.size() + 1);
	}
	cout<<result-1<<'\n';
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