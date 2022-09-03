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
#include <set>t

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

int n, m, t = 1;
// tree : connected acyclic graph
// dfs of bfs하면서 visited가 또 visited되는 경우 -> not tree

#define NO "No Trees.\n";
#define ONE "There is one tree.\n";
#define N(n) "A forest of " + to_string(n) + " trees.\n";


bool isCycle(int cur, int cur_parent, vector<bool>& visited, vector<vector<int>>& edges){
	visited[cur] = true;
	for(int adj : edges[cur]){
		if(adj == cur_parent) continue;
		if(visited[adj]) return true; // cycle이 있거나
		if(isCycle(adj, cur, visited, edges)) return true; // child의 cycle이 있는 경우
	}
	return false;
}

void solve(){
	int from, to;	
	vector<bool> visited(n+1, false); // [i] = false then not visited
	vector<vector<int>> edges(n+1); // [i] : edges start from vertex i
	for(int i = 0; i<m; i++){
		cin>>from>>to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	int answer = 0;
	for(int i = 1; i<=n; i++){
		if(!visited[i]){
			if(isCycle(i, 0, visited, edges) == false) answer++;	
		}
	}

	cout << "Case " << t; t++;
	if (answer == 0) cout << ": No trees.";
	else if (answer == 1) cout << ": There is one tree.";
	else cout << ": A forest of " << answer << " trees.";
	cout << '\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	while(1){
		cin>>n>>m;
		if(n == 0 && m == 0) break;
		solve();
	}

	return 0;
}
