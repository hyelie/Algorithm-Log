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
	string str; cin>>str;
	int days = 0, idx = 0, len = str.length();
	while(1){		
		set<char> s;
		while(1){
			if(s.size() < 3 || s.find(str[idx]) != s.end()){
				s.insert(str[idx]);
			}
			else{
				break;
			}
			idx++;
			if(idx >= len){
				break;
			}
		}
		days++;
		if(idx >= len) break;
	}
	cout<<days<<'\n';
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