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

struct cmp{
	bool operator()(pii &a, pii &b){
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second > b.second;
	}
};

void solve(){
	int N, K; cin>>N>>K;
	priority_queue<pii, vector<pii>, cmp> pq;
	pq.push({N, 0});
	int INF = 987654321;
	vector<int> dists(100001, INF);
	dists[N] = 0;

	while(!pq.empty()){
		int cur = pq.top().first;
		pq.pop();

		if(cur == K){
			break;
		}

		if(cur * 2 < 100001 && dists[2*cur] > dists[cur]){
			dists[2*cur] = dists[cur];
			pq.push({2*cur, dists[2*cur]});
		}
		if(cur - 1 >= 0 && dists[cur-1] > dists[cur] + 1){
			dists[cur-1] = dists[cur] + 1;
			pq.push({cur-1, dists[cur-1]});
		}
		if(cur + 1 < 100001 && dists[cur+1] > dists[cur] + 1){
			dists[cur+1] = dists[cur] + 1;
			pq.push({cur+1, dists[cur+1]});
		}
	}
	cout<<dists[K];
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}