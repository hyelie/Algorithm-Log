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

	while(!q.empty()){
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