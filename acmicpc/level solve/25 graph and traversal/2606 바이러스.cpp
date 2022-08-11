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

int N, M;
vector<vector<int>> edges;
vector<bool> visited;

void dfs(int cur){
	visited[cur] = true;
	for(int adj : edges[cur]){
		if(!visited[adj]){
			visited[adj] = true;
			dfs(adj);
		}
	}
}

void solve(){
	cin>>N>>M;
	edges.resize(N+1);
	visited.resize(N+1);
	fill(visited.begin(), visited.end(), false);

	int start, end;
	while(M--){
		cin>>start>>end;
		edges[start].push_back(end);
		edges[end].push_back(start);
	}

	dfs(1);
	int ans = 0;
	for(int i = 2; i<=N; i++){
		if(visited[i]) ans++;
	}
	cout<<ans;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}