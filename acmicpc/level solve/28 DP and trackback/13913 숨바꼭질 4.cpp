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

int N, K;
int INF = 987654321;
int LIMIT = 200001;

void solve(){
	cin>>N>>K;

	vector<int> dist(LIMIT, INF);
	vector<int> prev(LIMIT, -1);

	dist[N] = 0;
	queue<int> q; q.push(N);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == K) break;
	
		if(cur - 1 >= 0 && dist[cur - 1] == INF){
			dist[cur-1] = dist[cur] + 1;
			prev[cur-1] = cur;
			q.push(cur-1);
		}
		if(cur + 1 <= LIMIT && dist[cur + 1] == INF){
			dist[cur + 1] = dist[cur] + 1;
			prev[cur + 1] = cur;
			q.push(cur+1);
		}
		if(cur * 2 <= LIMIT && dist[cur * 2] == INF){
			dist[cur * 2] = dist[cur] + 1;
			prev[cur * 2] = cur;
			q.push(cur*2);
		}
	}

	int answer = dist[K];
	cout<<answer<<'\n';
	vector<int> trackback(++answer);
	while(answer--){
		trackback[answer] = K;
		K = prev[K];
	}
	trackback[0] = N;
	
	for(int elem : trackback) cout<<elem<<' ';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}