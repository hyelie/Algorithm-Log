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

void solve(){
	int m; cin>>m;

	int value = 1000000000;
	vector<int> rounds;
	while(value >= 1){
		rounds.push_back(value);
		value /= 10;
	}

	for(int v : rounds){
		if(m - v < 0) continue;
		else{
			cout<<m - v<<'\n';
			return;
		}
	}
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