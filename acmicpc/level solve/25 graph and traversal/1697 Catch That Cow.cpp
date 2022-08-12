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
	int N, K;
	cin>>N>>K;	

	int INF = 2222222;
	vector<int> dist(200001, INF);
	queue<int> q; q.push(N); dist[N] = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == K){
			cout<<dist[K];
			return;
		}
		if(0 <= cur - 1 && cur -1 <= 200000 && dist[cur - 1] > dist[cur] + 1 && dist[cur - 1] == INF){
			q.push(cur - 1);
			dist[cur - 1] = dist[cur] + 1;
		}
		if(0 <= cur + 1 && cur +1 <= 200000 && dist[cur + 1] > dist[cur] + 1 && dist[cur + 1] == INF){
			q.push(cur + 1);
			dist[cur + 1] = dist[cur] + 1;
		}
		if(0 <= cur * 2 && cur *2 <= 200000 && dist[2 * cur] > dist[cur] + 1 && dist[cur * 2] == INF){
			q.push(2 * cur);
			dist[2 * cur] = dist[cur] + 1;
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