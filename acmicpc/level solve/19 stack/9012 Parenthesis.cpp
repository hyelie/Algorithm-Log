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
	string s, result; cin>>s;
	int a = 0;
	for(int i = 0; i<s.length(); i++){
		if(s[i] == '(') a++;
		if(s[i] == ')') a--;

		if(a < 0){
			break;
		}
	}
	if(a != 0) result = "NO\n";
	else result = "YES\n";
	cout<<result;
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