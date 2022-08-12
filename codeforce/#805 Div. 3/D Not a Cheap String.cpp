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

bool cmp(pii &a, pii &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

void solve(){
	string w; cin>>w;
	int p; cin>>p;
	int total_p = 0;

	vector<pii> arr(w.length()); // .first : alphabet value, .second : index
	for(int i = 0; i<w.length(); i++){
		arr[i] = {w[i] - 'a' + 1, i};
		total_p += w[i] - 'a' + 1;
	}
	sort(arr.begin(), arr.end(), cmp);

	vector<bool> isDeleted(w.length(), false);
	for(pii &elem : arr){
		if(total_p <= p) break;
		total_p -= elem.first;
		isDeleted[elem.second] = true;
	}

	string result = "";
	for(int i = 0; i<w.length(); i++){
		if(!isDeleted[i]) result += w[i];
	}
	cout<<result<<'\n';
}

// 아마 greedy이고, [현재 point - p] > 0인 것 중 제일 큰 것 순대로 빼면 됨.
// origin w를 남기고, 
// sort 후 연산에

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