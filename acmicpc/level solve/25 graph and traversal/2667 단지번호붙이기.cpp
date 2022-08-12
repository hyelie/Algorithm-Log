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

int N;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
string board[26];
bool visited[26][26];
vector<int> num_houses;
int cnt;

void dfs(int r, int c){
	cnt++;
	visited[r][c] = true;

	for(int i = 0; i<4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(0 <= nr && nr < N && 0 <= nc && nc < N && !visited[nr][nc] && board[nr][nc] == '1'){
			visited[r][c] = true;
			dfs(nr, nc);
		}
	}
}

void solve(){
	cin>>N;
	for(int i = 0; i<N; i++) cin>>board[i];

	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			if(!visited[i][j] && board[i][j] == '1'){
				cnt = 0;
				dfs(i, j);
				num_houses.push_back(cnt);
			}
		}
	}
	sort(num_houses.begin(), num_houses.end(), less<int>());
	cout<<num_houses.size()<<'\n';
	for(int n : num_houses) cout<<n<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}