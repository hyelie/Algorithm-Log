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

int V;
vector<vector<pii>> edges;
vector<int> dists;
int INF = 2000000000;

void dfs(int cur_v, int cur_dist){
	dists[cur_v] = cur_dist;

	for(pii adjs : edges[cur_v]){
		int adj_v = adjs.first, adj_w = adjs.second;
		if(dists[adj_v] == INF){
			dfs(adj_v, cur_dist + adj_w);
		}
	}
}

void solve(){
	cin>>V;
	edges.resize(V+1);
	dists.resize(V+1);
	fill(dists.begin(), dists.end(), INF);

	for(int i = 1; i<=V; i++){
		int from, to, weight;
		cin>>from;
		while(1){
			cin>>to;
			if(to == -1) break;
			cin>>weight;
			edges[from].push_back({to, weight});
		}
	}

	dfs(1, 0);
	int answer = -1, max_v;
	for(int i = 1; i<=V; i++){
		if(answer < dists[i]){
			max_v = i;
			answer = dists[i];
		}
	}

	fill(dists.begin(), dists.end(), INF);
	dfs(max_v, 0);
	answer = -1;
	for(int i = 1; i<=V; i++){
		answer = max(answer, dists[i]);
	}
	cout<<answer;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}