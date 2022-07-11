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
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

// nlogn
void solve(){
	// input part
	string empty;
	getline(cin, empty);

	int n, k; cin>>n>>k; // n : # of vertex, k : # of things

	int x, y; cin>>x>>y; // from x to y

	int input; 
	vector<int> isThing(n+1, false); // isThing[i] == true then ith vertex is job
	for(int i = 0; i<k; i++){
		cin>>input;
		isThing[input] = true; // thing이 있는 house number
	}

	int from, to;
	vector<set<int>> edges(n+1); // edges[i] : edge set of ith vertex
	for(int i = 0; i<n-1; i++){
		cin>>from>>to; // n-1 edges (because of tree)
		edges[from].insert(to);
		edges[to].insert(from);
	}


	// delete all leafs
	queue<int> leafs;
	for(int i = 1; i<=n; i++){
		if(isThing[i] == true || i == x || i == y) continue;
		if(edges[i].size() == 1){
			leafs.push(i);
		}
	}

	// leaf node는 단 1개의 edge밖에 없다.
	while(!leafs.empty()){
		int cur_node = leafs.front(); leafs.pop();
		if(isThing[cur_node] == true || cur_node == x || cur_node == y) continue;
		else{
			if(edges[cur_node].size() == 1){
				int to = *edges[cur_node].begin();
				edges[cur_node].clear();
				edges[to].erase(edges[to].find(cur_node));
				leafs.push(to);
			}
		}
	}

	vector<bool> visited(n+1, false);
	// calculate dist from x to y
	visited[x] = true;
	queue<pii> q; q.push({x, 0}); // .first : vertex number ,.second : dist from x
	int dist_x_to_y = -1, cur_node, cur_dist;
	while(!q.empty()){
		cur_node = q.front().first, cur_dist = q.front().second; q.pop();
		if(cur_node == y){
			dist_x_to_y = cur_dist;
			break;
		}
		for(int next_node : edges[cur_node]){
			if(visited[next_node] == false){
				visited[next_node] = true;
				q.push({next_node, cur_dist + 1});
			}
		}
	}

	// get answer
	int answer = -1 * dist_x_to_y;
	for(int i = 1; i<=n; i++){
		answer += (int)edges[i].size();
	}
	cout<<answer<<'\n';
}

/*
tree로 된 것에서
시작점 x, 도착점 y에 대해
x - a1, ... , ak - y에 대해 움직이는 경우 최소화

x를 root로 잡고 시작
a에 없고, x, y가 아닌 leaf node를 더 이상 삭제되지 않을 때 까지 모두 삭제
 -> leaf node는 a에 속해 있거나, y일 것이다. (queue 이용)
reduced graph의 모든 edge는 euler tour로 탐색 가능할 것이다. 다만, x to y의 경로는 1번만 방문되면 된다.
따라서 # of edges in reduced edge * 2 - # of edges in x to y가 답일 것.

*** euler path에 관해 정리할 것
1) leaf를 다 뺀다는 생각
2) 전체 edge에서 x to y를 뺀다는 생각
레전드!

진짜 레전드다 모르면 맞아야지

*/

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}