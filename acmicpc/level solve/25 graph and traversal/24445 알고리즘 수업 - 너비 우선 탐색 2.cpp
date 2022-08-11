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

void solve(){
	cin>>N>>M>>R;
	vector<vector<int>> edges(N+1);
	vector<bool> visited(N+1, false);
	vector<int> nums(N+1, 0);

	int start, end;
	while(M--){
		cin>>start>>end;
		edges[start].push_back(end);
		edges[end].push_back(start);
	}
	for(vector<int> &edge : edges) sort(edge.begin(), edge.end(), greater<int>());

	queue<int> q;
	q.push(R); visited[R] = true;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		nums[cur] = cnt++;

		for(int adj : edges[cur]){
			if(!visited[adj]){
				q.push(adj);
				visited[adj] = true;
			}
		}
	}

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