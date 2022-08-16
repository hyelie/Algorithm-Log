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

int n, m, t; 
int s, g, h; 
int INF = 987654321;

struct cmp{
	bool operator()(pii &a, pii &b){
		if(a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};

// dijkstra from vertex "from"
vector<int> dijkstra(int from, int s, vector<vector<pii>>& edges){
	vector<int> dists(n+1, INF);	
	priority_queue<pii, vector<pii>, cmp> pq;
	dists[from] = 0;
	pq.push({from, 0});

	while(!pq.empty()){
		int cur = pq.top().first; pq.pop();
		for(pii adjs : edges[cur]){
			int adj = adjs.first, weight = adjs.second;
			if(dists[adj] > dists[cur] + weight){
				dists[adj] = dists[cur] + weight;
				pq.push({adj, dists[adj]});
			}
		}
	}
	return dists;
}

void solve(){
	cin>>n>>m>>t;
	cin>>s>>g>>h;
	vector<vector<pii>> edges(n+1);
	while(m--){
		int from, to, weight;
		cin>>from>>to>>weight;
		edges[from].push_back({to, weight});
		edges[to].push_back({from, weight});
	}
	vector<int> targets(t); // .first : target num, .second : weight from s to this
	for(int i = 0; i<t; i++){
		cin>>targets[i];
	}

	vector<int> s_all, g_all, h_all;
	s_all = dijkstra(s, s, edges);
	g_all = dijkstra(g, s, edges);
	h_all = dijkstra(h, s, edges);

	set<int> answer;
	for(int& target : targets){
		int s_g = s_all[g], g_h = g_all[h], h_target = h_all[target];
		if(s_g != INF && g_h != INF && h_target != INF){
			if(s_g + g_h + h_target == s_all[target]) answer.insert(target);
		}

		int s_h = s_all[h], h_g = h_all[g], g_target = g_all[target];
		if(s_h != INF && h_g != INF && g_target != INF){
			if(s_h + h_g + g_target == s_all[target]) answer.insert(target);
		}
	}

	for(int ans : answer) cout<<ans<<' ';
	cout<<'\n';

	/*
	s - g, g - h, h - target
	s - h, h - g, g - target
	이 2개 route의 weight 중 적어도 1개와 s-target의 weight가 같으면 target은 올바른 목표
	*/
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