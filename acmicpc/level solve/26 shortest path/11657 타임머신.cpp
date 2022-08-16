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

typedef pair<ll, ll> pll;
void solve(){
	ll N, M; cin>>N>>M;
	ll INF = 987654321;
	vector<ll> dists(N+1, INF);
	vector<vector<pll>> edges(N+1);
	ll from, to, weight;
	while(M--){
		cin>>from>>to>>weight;
		edges[from].push_back({to, weight});
	}

	// 갱신
	dists[1] = 0;
	for(ll i = 1; i<=N-1; i++){
		for(ll v = 1; v<=N; v++){ // for all vertex
			for(pii adj : edges[v]){
				if(dists[v] == INF) continue;
				if(dists[adj.first] > dists[v] + adj.second){
					dists[adj.first] = dists[v] + adj.second;
				}
			}
		}
	}

	// cycle 검사
	for(ll v = 1; v<=N; v++){ // for all vertex
		for(pii adj : edges[v]){
			if(dists[v] == INF) continue;
			if(dists[adj.first] > dists[v] + adj.second){
				cout<<"-1";
				return;
			}
		}
	}

	for(ll i = 2; i<=N; i++){
		cout<<(dists[i] == INF ? -1 : dists[i])<<'\n';
	}
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}