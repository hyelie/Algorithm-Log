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

int num_red = 0;

pii getMostDuplicateString(string& t, vector<bool>& isRed, vector<string> &sarr){
	int dup_num = -1, idx = -1, start_idx = -1;
	for(int i = 0; i<sarr.size(); i++){
		int nth_idx = 0;
		while(1){
			nth_idx = t.find(sarr[i], nth_idx);
			if(nth_idx == string::npos) break;
			int cnt = 0;
			for(int k = nth_idx; k<nth_idx + sarr[i].size(); k++){
				if(!isRed[k]) cnt++;
			}
			if(dup_num < cnt){
				dup_num = cnt;
				idx = i;
				start_idx = nth_idx;
			}
			nth_idx++;
		}
	}
	return {idx, start_idx};
}

bool checkAllRed(vector<bool>& isRed){
	for(int i = 0; i<isRed.size(); i++){
		if(!isRed[i]) return false;
	}
	return true;
}

void solve(){
	string t; cin>>t; // text
	vector<bool> isRed(t.size(), false);
	int n; cin>>n; // number of strings in the set
	vector<string> sarr(n); // string in the set.
	
	for(int i = 0; i<n; i++){
		cin>>sarr[i];
	}

	vector<pii> answer;
	while(checkAllRed(isRed)){
		pii result = getMostDuplicateString(t, isRed, sarr);
		int md_idx = result.first; // most duplicate sarr idx
		int start_idx = result.second;

		if(md_idx == -1){
			answer.resize(0);
			break;
		}
		for(int k = start_idx; k<start_idx + sarr[md_idx].length(); k++){
			if(!isRed[k]){
				isRed[k] = true;
			}
		}
		answer.push_back({md_idx + 1, start_idx + 1});
	}

	if(answer.size() != 0){
		cout<<answer.size()<<'\n';
		for(pii elem : answer){
			cout<<elem.first<<' '<<elem.second<<'\n';
		}
	}
	else{
		cout<<"-1\n";
	}



	

	// 불가하다먼 -1
	// 가능하다면 횟수 m
	// m개의 line은 wj, pj로 나타내지며 wj번째 string이 t의 pj번째 index에서 색칠했다는 것.

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