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

struct cmp{
	bool operator()(pii &a, pii &b){
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second > b.second;
	}
};

void solve(){
	int V, E, K; cin>>V>>E>>K;
	int from, to, weight, INF = 987654321;
	vector<vector<pii>> edges(V+1);
	vector<int> dists(V+1, INF); dists[K] = 0;
	while(E--){
		cin>>from>>to>>weight;
		edges[from].push_back({to, weight});
		//edges[to].push_back({from, weight});
	}

	priority_queue<pii, vector<pii>, cmp> q; q.push({K, dists[K]});
	while(!q.empty()){
		pii cur = q.top(); q.pop();
		from = cur.first;
		for(pii adj : edges[from]){
			to = adj.first;
			weight = adj.second;
			if(dists[to] > cur.second + weight){
				dists[to] = cur.second + weight;
				q.push({to, dists[to]});
			}
		}
	}

	for(int i = 1; i<=V; i++){
		if(dists[i] == INF) cout<<"INF\n";
		else cout<<dists[i]<<'\n';
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