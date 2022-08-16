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

typedef pair<int, string> pis;

////////////////////// write your code below


void solve(){
	int V, E; cin>>V>>E;
	int INF = 987654321;
	vector<vector<int>> dists(V+1, vector<int>(V+1, INF));
	int from, to, weight;
	while(E--){
		cin>>from>>to>>weight;
		dists[from][to] = weight;
	}

	for(int temp = 1; temp<=V; temp++){
		for(int from = 1; from <= V; from++){
			for(int to = 1; to <=  V; to++){
				dists[from][to] = min(dists[from][to], dists[from][temp] + dists[temp][to]);
			}
		}
	}

	int answer = INF;
	for(int i = 1; i<=V; i++){
		answer = min(answer, dists[i][i]);
	}
	cout<<(answer == INF ? -1 : answer);
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}