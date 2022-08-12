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

int dr[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dc[8] = {1, -1, 2, -2, 2, -2, 1, -1};

void solve(){
	int l; cin>>l;
	vector<vector<int>> dist(l, vector<int>(l, -1));

	pii start, destination;
	cin>>start.first>>start.second>>destination.first>>destination.second;
	queue<pii> q; q.push(start); dist[start.first][start.second] = 0;
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		if(cur.first == destination.first && cur.second ==destination.second){
			cout<<dist[cur.first][cur.second]<<'\n';
			return;
		}

		for(int d = 0; d<8; d++){
			int nr = cur.first + dr[d];
			int nc = cur.second + dc[d];
			if(0 <= nr && nr < l && 0 <= nc && nc < l && dist[nr][nc] == -1){
				dist[nr][nc] = dist[cur.first][cur.second] + 1;
				q.push({nr, nc});
			}
		}
	}
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