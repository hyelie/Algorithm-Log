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

int N, M, R, cnt = 1; 
vector<bool> visited;
vector<vector<int>> edges; // edges[i] : edge list starts from i
vector<int> visit_num;

void dfs(int cur_node){
	if(visited[cur_node]) return;

	visit_num[cur_node] = cnt++;
	visited[cur_node] = true;
	for(int adjacent : edges[cur_node]){
		if(!visited[adjacent]){
			dfs(adjacent);
		}
	}
}

void solve(){
	cin>>N>>M>>R;
	visited.resize(N+1);
	fill(visited.begin(), visited.end(), false);
	edges.resize(N+1);
	visit_num.resize(N+1);
	fill(visit_num.begin(), visit_num.end(), 0);
	
	int start, end;
	for(int i = 0; i<M; i++){
		cin>>start>>end;
		edges[start].push_back(end);
		edges[end].push_back(start);
	}
	for(vector<int>& vi : edges){
		sort(vi.begin(), vi.end(), less<int>());
	}

	dfs(R);

	for(int i = 1; i<=N; i++) cout<<visit_num[i]<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}