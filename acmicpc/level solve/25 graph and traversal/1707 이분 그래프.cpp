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

int dr[6] = {0, 1, 0, -1, 0, 0};
int dc[6] = {1, 0, -1, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

struct coor{
	int r, c, h;
};

void solve(){
	int N, M, H; cin>>M>>N>>H;
	vector<vector<vector<int>>> grid(H, vector<vector<int>>(N, vector<int>(M)));
	vector<vector<vector<int>>> date(H, vector<vector<int>>(N, vector<int>(M, 0)));
	queue<coor> q;
	coor c;
	for(int h = 0; h<H; h++){
		for(int n = 0; n<N; n++){
			for(int m = 0; m<M; m++){
				cin>>grid[h][n][m];
				c.r = n; c.c = m; c.h = h;
				if(grid[h][n][m] == 1)q.push(c);
			}
		}
	}

	while(!q.empty()){ㅁ#define _USE_MATH_DEFINES 
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

string no = "NO\n", yes = "YES\n";

bool isBipartite(int start_node, vector<vector<int>>& edges, vector<int>& colors){
	queue<int> q; // vertex number
	colors[start_node] = 1;
	q.push(start_node);

	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int adj : edges[cur]){
			if(colors[adj] == colors[cur]) return false;
			if(colors[adj] == 0){ // unvisited
				colors[adj] = 3 - colors[cur]; // red then black, black then red
				q.push(adj);
			}
		}
	}
	return true;
}

void solve(){
	int n; cin>>n; // 짝수
	int e; cin>>e;
	vector<vector<int>> edges(n);
	vector<int> colors(n, 0); // 0 : nothing, 1 : red, 2 : black

	int from, to;
	for(int i = 0; i<e; i++){
		cin>>from>>to;
		from--; to--;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	for(int i = 0; i<n; i++){
		if(colors[i] == 0){
			if(!isBipartite(i, edges, colors)){
				cout<<no;
				return;
			}
		}
	}
	cout<<yes;
	return;

	// 이게 왜 동작을 안하는지는 잘 모르겠는데,
	// bipartite 검증이라는 생각이 팍 든다. 모든 subgraph가 bipartite then true, else false 감이다.
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
		coor cur = q.front(); q.pop();
		for(int d = 0; d<6; d++){
			int nr = cur.r + dr[d];
			int nc = cur.c + dc[d];
			int nh = cur.h + dh[d];
			if(0 <= nr && nr < N && 0 <= nc && nc < M && 0 <= nh && nh < H &&  grid[nh][nr][nc] == 0){
				grid[nh][nr][nc] = 1;
				date[nh][nr][nc] = date[cur.h][cur.r][cur.c] + 1;
				c.r = nr; c.c = nc; c.h = nh;
				q.push(c);
			}
		}
	}

	int max_date = -1;
	for(int h = 0; h<H; h++){
		for(int n = 0; n<N; n++){
			for(int m = 0; m<M; m++){
				if(grid[h][n][m] == 0){
					cout<<"-1";
					return;
				}
				max_date = max(max_date, date[h][n][m]);
			}
		}
	}
	cout<<max_date;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}