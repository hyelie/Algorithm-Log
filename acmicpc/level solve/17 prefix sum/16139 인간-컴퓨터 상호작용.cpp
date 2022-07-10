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
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	string s; cin>>s;

	vector<vector<int>> psum(26, vector<int>(s.length(), 0));
	// psum[i][j] : j번째 index까지 i번째 alphabet의 개수;

	psum[s[0] - 'a'][0]++;
	for(int i = 1; i<s.length(); i++){
		for(int ai = 0; ai<26; ai++){
			psum[ai][i] = psum[ai][i-1];
		}
		psum[s[i] - 'a'][i]++;
	}

	int q; cin>>q;
	while(q--){
		char alphabet; int l, r;
		cin>>alphabet>>l>>r;

		if(l == 0) cout<<psum[alphabet - 'a'][r]<<'\n';
		else cout<<psum[alphabet - 'a'][r] - psum[alphabet - 'a'][l-1]<<'\n';
	}

	//////////////////////

	return 0;
}