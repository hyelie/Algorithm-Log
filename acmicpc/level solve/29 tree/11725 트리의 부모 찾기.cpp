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

int N;
vector<vector<int>> edges;
vector<int> parents;

void dfs(int cur){
	for(int adj : edges[cur]){
		if(parents[adj] == -1){
			parents[adj] = cur;
			dfs(adj);
		}
	}
}

void solve(){
	cin>>N;
	edges.resize(N+1);
	parents.resize(N+1);
	fill(parents.begin(), parents.end(), -1); // if not visited, then -1
	int from, to;
	for(int i = 0 ;i<N-1; i++){
		cin>>from>>to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	parents[1] = 1;
	dfs(1);

	for(int i = 2; i<=N; i++) cout<<parents[i]<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}