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
	string s; cin>>s; // a로만 구성
	string t; cin>>t; // lowercase, 50 이하
	
	
	// t가 "a"인 경우 : 1개
	// t가 "*a*"인 경우 : INF개
	if(t == "a"){
		cout<<"1\n";
		return;
	}

	for(int i = 0; i<t.length(); i++){
		if(t[i] == 'a'){
			cout<<"-1\n";
			return;
		}
	}
	/*
		a를 t와 바꾸는 것
		2^(sl)
	*/
	ll cnt = 1, sl = s.length();
	while(sl--){
		cnt *= 2LL;
	}
	cout<<cnt<<'\n';
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