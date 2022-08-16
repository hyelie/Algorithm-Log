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

int N, E;
vector<vector<pii>> edges;
int INF = 987654321;

struct cmp{
	bool operator()(pii &a, pii &b){
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second > b.second;
	}
};

int dijkstra(int start, int end){
	vector<int> dists(N+1, INF); dists[start] = 0;

	priority_queue<pii, vector<pii>, cmp> pq;
	pq.push({start, dists[start]});
	while(!pq.empty()){
		pii cur = pq.top(); pq.pop();
		int cur_v = cur.first;
		for(pii adj : edges[cur_v]){
			int adj_v = adj.first, adj_w = adj.second;
			if(dists[adj_v] > dists[cur_v] + adj_w){
				dists[adj_v] = dists[cur_v] + adj_w;
				pq.push({adj_v, dists[adj_v]});
			}
		}
	}

	return dists[end];
}

void solve(){
	cin >> N >> E;
	
	int from, to, weight;
	edges.resize(N+1);
	while (E--)	{
		cin >> from >> to >> weight;
		edges[from].push_back({to, weight});
		edges[to].push_back({from, weight});
	}
	int v1, v2;
	cin >> v1 >> v2;

	int one_v1 = dijkstra(1, v1), one_v2 = dijkstra(1, v2);
	int v1_v2 = dijkstra(v1, v2);
	int v1_n = dijkstra(v1, N), v2_n = dijkstra(v2, N);

	// v1_v2가 INF거나
	// v1_v2는 값 있는데,
	// [1-v1 == INF or v2-n == INF] (1-v1-v2-n이 없음)
	// [1-v2 == INF or v1-n == INF] (1-v2-v1-n이 없음)
	// 위 두 조건을 다 만족하면 없는 것
	if(v1_v2 == INF || ((one_v1 == INF || v2_n == INF) && (one_v2 == INF || v1_n == INF))){
		cout<<-1;
	}
	else{
		cout<<min(one_v1 + v2_n, one_v2 + v1_n) + v1_v2;
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