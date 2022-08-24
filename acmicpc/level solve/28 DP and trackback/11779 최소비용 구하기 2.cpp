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

struct mycomp{
    bool operator()(pii&a, pii&b){
        return a.second > b.second; // weight가 큰 것을 앞으로
    }
};

void solve(){
	int n, m; cin>>n>>m;
	vector<vector<pii>> edges(n+1);
	int from, to, weight;
	while(m--){
		cin>>from>>to>>weight;
		edges[from].push_back({to, weight});
	}
	cin>>from>>to;

	int INF = 987654321;
	vector<int> dist(n+1, INF); dist[from] = 0;
	vector<int> prev(n+1);
    priority_queue<pii, vector<pii>, mycomp> pq; pq.push({from, 0});
    while(!pq.empty()){
        int cur = pq.top().first;
        int cur_weight = pq.top().second;
        pq.pop();

		// 같은 경로지만 cost가 다른 경우를 대비해 아래 로직 넣음
		if(dist[cur] < cur_weight) continue;
        
        // pq.top()에 연결된 모든 edge에 대해 dijkstra 수행
        for(pii &adjs : edges[cur]){
            int adj = adjs.first, adj_weight = adjs.second;
            
            // 만약 갱신 가능하다면 dist 갱신 이후 pq에 다시 넣음
            if(dist[adj] > dist[cur] + adj_weight){
                dist[adj] = dist[cur] + adj_weight;
                pq.push({adj, dist[adj]});
				prev[adj] = cur;
            }
        }
    }

	cout<<dist[to]<<'\n';
	stack<int> stk;
	while(to != from){
		stk.push(to);
		to = prev[to];
	}
	stk.push(to);
	cout<<stk.size()<<'\n';
	while(!stk.empty()){
		cout<<stk.top()<<' ';
		stk.pop();
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