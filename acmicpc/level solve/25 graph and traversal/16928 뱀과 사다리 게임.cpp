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

void solve(){
	int N, M; cin>>N>>M;
	map<int, int> m; // m[i] : i번째 칸에서 출발했을 때 도착하는 칸
	for(int i = 0; i<N + M; i++){
		int start, end; cin>>start>>end;
		m[start] = end;
	}
	queue<int> q; q.push(1); // 시작 칸
	vector<int> dist(101, -1); dist[0] = dist[1] = 0;

	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == 100){
			cout<<dist[100];
			return;
		}
		for(int i = 1; i<=6; i++){
			int next = cur + i;
			if(m.find(next) != m.end()) next = m[next];
			if(next > 100 || dist[next] != -1) continue;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}