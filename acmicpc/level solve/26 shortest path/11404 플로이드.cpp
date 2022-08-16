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
	int n, m; cin>>n>>m;
	int INF = 999999999; 
	vector<vector<int>> dists(n+1, vector<int>(n+1, INF)); // dists[from][to] : from에서 to까지 distance
	int from, to, weight;
	while(m--){
		cin>>from>>to>>weight;
		dists[from][to] = min(dists[from][to], weight);
	}
	for(int i = 1; i<=n; i++) dists[i][i] = 0;
	for(int temp = 1; temp <= n; temp++){
		for(int from = 1; from <= n; from++){
			for(int to = 1; to <= n; to++){
				dists[from][to] = min(dists[from][to], dists[from][temp] + dists[temp][to]);
			}
		}
	}

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			int result = dists[i][j];
			result = (result == INF ? 0 : result);
			cout<<result<<' ';
		}
		cout<<'\n';
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