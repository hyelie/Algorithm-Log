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

int N, M, V;
vector<int> edges[1001];
vector<int> dfs_visited(1001), bfs_visited(1001);

void dfs(int cur){
	cout<<cur<<' ';
	dfs_visited[cur] = true;

	for(int adj : edges[cur]){
		if(!dfs_visited[adj]){
			dfs_visited[adj] = true;
			dfs(adj);
		}
	}
}

void bfs(int cur){
	queue<int> q;
	q.push(cur);
	bfs_visited[cur] = true;

	while(!q.empty()){
		cur = q.front(); q.pop();
		cout<<cur<<' ';
		for(int adj : edges[cur]){
			if(!bfs_visited[adj]){
				bfs_visited[adj] = true;
				q.push(adj);
			}
		}
	}
}

void solve(){
	cin>>N>>M>>V;
	int start, end;
	while(M--){
		cin>>start>>end;
		edges[start].push_back(end);
		edges[end].push_back(start);
	}
	for(int i = 1; i<=N; i++) sort(edges[i].begin(), edges[i].end(), less<int>());

	dfs(V);
	cout<<'\n';
	bfs(V);
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}