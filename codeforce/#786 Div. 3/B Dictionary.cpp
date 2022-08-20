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

vector<string> bl;

void init(){
	for (char c = 'a'; c <= 'z'; c++){
		for (char cc = 'a'; cc <= 'z'; cc++){
			string empty = "";
			empty += c;
			empty += cc;
			if (c == cc)
				continue;
			else
				bl.push_back(empty);
		}
	}
	sort(bl.begin(), bl.end(), less<string>());
}


void solve(){
	string s; cin>>s;
	cout<<find(bl.begin(), bl.end(), s) - bl.begin() + 1 <<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	init();
	while(t--){
		solve();
	}

	return 0;
}