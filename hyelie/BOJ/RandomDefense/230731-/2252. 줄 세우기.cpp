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

vector<vector<int>> edges; // edges[i] : src가 i인 edge array
vector<int> incoming_edge_nums; // incoming_edge_nums[i] : dest가 i인 edge 개수
queue<int> q; // incoming_edge_nums[i]가 0인 vertex들이 들어감. (다음 topological sort 대상)

void solve(){
	// input
	int N, M; cin>>N>>M;
	edges.resize(N+1);
	incoming_edge_nums.resize(N+1);
	fill(incoming_edge_nums.begin(), incoming_edge_nums.end(), 0);
	int src, dest;
	while(M--){
		cin>>src>>dest;
		edges[src].push_back(dest);
		incoming_edge_nums[dest]++;
	}

	// topological info setup
	for(int i = 1; i<=N; i++){
		if(incoming_edge_nums[i] == 0) q.push(i);
	}
	vector<int> result(N);

	// topological sort
	for(int i = 0; i<N; i++){
		if(q.empty()) return;

		int cur = q.front(); q.pop();
		result[i] = cur;
		for(int next : edges[cur]){
			if(incoming_edge_nums[next] == 0) continue;
			else{
				incoming_edge_nums[next]--;
				if(incoming_edge_nums[next] == 0) q.push(next);
			}
		}
	}

	// print result
	for(int i : result) cout<<i<<' ';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}