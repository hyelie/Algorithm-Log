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

ll n = 200000;
vector<vector<ll>> childs(n+1); // childs[i] : vertex i의 child list
vector<ll> a(n+1), b(n+1); // a[i] : aj value from p[i] to i

vector<ll> b_psum; // bj의 psum
vector<ll> answer;

void DFS(ll parent, ll ajsum){
	for(ll child : childs[parent]){
		ajsum += a[child];
		b_psum.push_back((b_psum.empty() ? 0LL : b_psum[b_psum.size()-1])+ b[child]);

		answer[child] = upper_bound(b_psum.begin(), b_psum.end(), ajsum) - b_psum.begin();
		DFS(child, ajsum);

		ajsum -= a[child];
		b_psum.pop_back();
	}
}

void solve(){
	cin>>n; // n : # of vertices
	ll pj, aj, bj;
	
	for(ll i = 0; i<=n; i++){ // reset
		childs[i].resize(0);
	}
	for(ll i = 2; i<=n; i++){
		cin>>pj>>aj>>bj; // pj : vertex j의 parent, [pj - j]의 edge
		childs[pj].push_back(i);
		a[i] = aj;
		b[i] = bj;
	}

	b_psum.resize(0);
	answer.resize(n+1);

	DFS(1, 0);
	for(ll i = 2; i<=n; i++) cout<<answer[i]<<' ';
	cout<<'\n';

	/*
		[root to i] path에서 aj의 sum = Ai
		ri = sum of bj가 Ai보다 작거나 같은 maximum prefix

		6 : ajsum = 2, bj 누적합 = [1], ajsum의 upper bound : 2 -> 1
		8 : ajsum = 6, bj 누적합 = [1, 4], ajsum의 upper bound : 3 -> 2
		9 : ajsum = 7, bj 누적합 = [1, 4, 7], ajsum의 upper bound : 4 -> 3

		2 : ajsum : 5, bj누적합 = [6], ajsum의 uppber bound : 1 -> 0
		4 : ajsum : 14, bj누적합 = [6, 16], ajsum의 upper bound : 2 -> 1
		3 : ajsum = 19, bj누적합 = [6, 16, 17], ajsum의 upper bound : 4 -> 3

		root부터 leaf까지 [누적 aj, [bj의 psum]] 이렇게 내려가게 하고 bj의 psum에서 aj의 ub 찾으면 된다.
	*/
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