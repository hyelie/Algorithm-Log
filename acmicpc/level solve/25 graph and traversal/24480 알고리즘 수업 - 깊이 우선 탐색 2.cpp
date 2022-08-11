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

int N, M, R;
vector<vector<int>> edges;
vector<int> nums;
vector<bool> visited;
int cnt = 1;

void dfs(int cur){
	nums[cur] = cnt++;
	visited[cur] = true;

	for(int adj : edges[cur]){
		if(!visited[adj]){
			visited[adj] = true;
			dfs(adj);
		}
	}
}

void solve(){
	cin>>N>>M>>R;
	edges.resize(N+1);
	nums.resize(N+1);
	visited.resize(N+1);
	fill(visited.begin(), visited.end(), false);
	int start, end;
	while(M--){
		cin>>start>>end;
		edges[start].push_back(end);
		edges[end].push_back(start);
	}
	for(int i = 1; i<=N; i++) sort(edges[i].begin(), edges[i].end(), greater<int>());

	dfs(R);

	for(int i = 1; i<=N; i++) cout<<nums[i]<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}