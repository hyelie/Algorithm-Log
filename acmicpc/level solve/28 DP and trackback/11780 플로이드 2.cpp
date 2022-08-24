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
	int INF = 987654321;
	vector<vector<int>> dists(n+1, vector<int>(n+1, INF)), prev(n+1, vector<int>(n+1));
	int from, to, weight;
	while(m--){
		cin>>from>>to>>weight;
		if(dists[from][to] > weight){
			dists[from][to] = weight;
			prev[from][to] = from;
		}
	}

	for(int temp = 1; temp<=n; temp++){
		for(int from=1; from<=n; from++){
			for(int to = 1; to<=n; to++){
				if(from == to) continue;
				if(dists[from][to] > dists[from][temp] + dists[temp][to]){
					dists[from][to] = dists[from][temp] + dists[temp][to];
					prev[from][to] = prev[temp][to];
				}
			}
		}
	}

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cout<<(dists[i][j] == INF? 0 : dists[i][j])<<' ';
		}
		cout<<'\n';
	}

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(dists[i][j] == INF){
				cout<<0<<'\n';
				continue;
			}
			int dest = j;
			stack<int> stk; stk.push(dest);
			while(dest != i){
				dest = prev[i][dest];
				stk.push(dest);
			}

			cout<<stk.size();
			while(!stk.empty()){
				cout<<' '<<stk.top(); stk.pop();
			}
			cout<<'\n';
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