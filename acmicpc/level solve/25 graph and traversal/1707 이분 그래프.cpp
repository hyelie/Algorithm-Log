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

string no = "NO\n", yes = "YES\n";

bool isBipartite(int start_node, vector<vector<int>>& edges, vector<int>& colors){
	queue<int> q; // vertex number
	colors[start_node] = 1;
	q.push(start_node);

	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int adj : edges[cur]){
			if(colors[adj] == colors[cur]) return false;
			if(colors[adj] == 0){ // unvisited
				colors[adj] = 3 - colors[cur]; // red then black, black then red
				q.push(adj);
			}
		}
	}
	return true;
}

void solve(){
	int n; cin>>n; // 짝수
	int e; cin>>e;
	vector<vector<int>> edges(n);
	vector<int> colors(n, 0); // 0 : nothing, 1 : red, 2 : black

	int from, to;
	for(int i = 0; i<e; i++){
		cin>>from>>to;
		from--; to--;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	for(int i = 0; i<n; i++){
		if(colors[i] == 0){
			if(!isBipartite(i, edges, colors)){
				cout<<no;
				return;
			}
		}
	}
	cout<<yes;
	return;

	// 이게 왜 동작을 안하는지는 잘 모르겠는데,
	// bipartite 검증이라는 생각이 팍 든다. 모든 subgraph가 bipartite then true, else false 감이다.
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