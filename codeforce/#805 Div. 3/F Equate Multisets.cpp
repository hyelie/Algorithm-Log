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
	int n; cin>>n;
	int ai, bi;
	multiset<int> a, b;
	for(int i = 0; i<n; i++){
		cin>>ai;
		while(ai % 2 == 0) ai /= 2;
		a.insert(ai);
	}
	for(int i = 0; i<n; i++){
		cin>>bi;
		while(bi % 2 == 0) bi /= 2;
		b.insert(bi);
	} // 나눌 수 있는 최대로 나누기

	while(!b.empty()){
		int belem = *b.begin();
		if(a.find(belem) == a.end()){ // not found in a
			if(belem == 0) break; // 만약 b가 0이라면 못 찾은 것
			b.erase(b.find(belem));
			b.insert(belem/2);
		}
		else{ // found
			b.erase(b.find(belem));
			a.erase(a.find(belem));
		} // multiset 특 : erase(value) 하면 value값 전부 지워짐. 따라서 iter로 지워야 함
	}

	cout<<(b.empty()?"YES\n":"NO\n");
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