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

void solve(){
	string t; cin>>t; // text
	int n; cin>>n; // number of strings in the set
	vector<string> sarr(n); // string in the set.
	
	for(int i = 0; i<n; i++){
		cin>>sarr[i];
	}

	vector<pii> answer;
	int blackidx = 0, prevbidx = -1; 
	// blackidx : 아직 black인 index 중 제일 왼쪽 것
	// prevbidx : 이전 blackidx
	//while(blackidx < t.length()){
	while(blackidx < t.length()){
		int blackidx_temp = blackidx;
		int prevbidx_temp = -1;
		int sarridx_temp = -1;
		for(int tidx = prevbidx + 1; tidx <= blackidx; tidx++){
			for(int i = 0; i<n; i++){
				if(t.substr(tidx, sarr[i].length()) == sarr[i]){
					if(blackidx_temp < (int)(tidx + sarr[i].length())){ // 최대한 뒤로 늘림
						prevbidx_temp = tidx;
						blackidx_temp = tidx + sarr[i].length();
						sarridx_temp = i;
					}
				}
			}
		}
		if(prevbidx_temp == -1){
			cout<<"-1\n";
			return;
		}
		blackidx = blackidx_temp;
		prevbidx = prevbidx_temp;
		answer.push_back({sarridx_temp+1, prevbidx_temp + 1});
	}
	cout<<answer.size()<<'\n';
	for(pii &p : answer){
		cout<<p.first<<' '<<p.second<<'\n';
	}

	/*
	첫 단계는 max length prefix를 찾는 것이다. 그 단어가 없다면 색칠 불가
	찾았다면  
	*/



	

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