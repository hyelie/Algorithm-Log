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

int n;
vector<vector<pii>> edges;
int INF = 987654321;

struct cmp{
	bool operator()(pii &a, pii &b){
		if(a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};


// .first : vertex number, .second : value
pii dijkstra(int start){
	vector<int> dists(n+1, INF); dists[start] = 0;
	priority_queue<pii, vector<pii>, cmp> pq;
	pq.push({start, 0});
	while(!pq.empty()){
		pii curs = pq.top(); pq.pop();
		int cur = curs.first, cur_dist = curs.second;
		if(dists[cur] < cur_dist) continue;
		for(pii adjs : edges[cur]){
			int adj = adjs.first, adj_dist = adjs.second;
			if(dists[adj] > dists[cur] + adj_dist){
				dists[adj] = dists[cur] + adj_dist;
				pq.push({adj, dists[adj]});
			}
		}
	}

	pii answer = {-1, -1};
	for(int i = 1; i<=n; i++){
		if(dists[i] > answer.second){
			answer.second = dists[i];
			answer.first = i;
		}
	}
	return answer;
}

void solve(){
	cin>>n;
	edges.resize(n+1);
	int from, to, weight;
	for(int i = 0; i<n-1; i++){
		cin>>from>>to>>weight;
		edges[from].push_back({to, weight});
		edges[to].push_back({from, weight});
	}

	pii first_end = dijkstra(1);
	pii second_end = dijkstra(first_end.first);
	cout<<second_end.second;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}