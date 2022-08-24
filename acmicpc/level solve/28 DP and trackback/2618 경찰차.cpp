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

int N, W, INF = 987654321;
vector<pii> arr;
vector<vector<int>> dp;
vector<int> trackback;
// dp[i][j] : 1번이 i번을, 2번이 j번을 마지막으로 해결했을 때 탐색 종료까지
// 0번 : 아무것도 하지 않은 경우

int dist(pii a, pii b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

// dfs(i, j) : 1번이 i번을, 2번이 j번을 마지막으로 탐색했을 때 탐색 종료까지 최솟값
int dfs(int i, int j){
	// dfs + dp를 보자.
	if(i == W || j == W){ // 둘 중 하나라도 끝에 도달한 경우 더 이상 탐색 필요 없음.
		return 0;
	}
	if(dp[i][j] != INF) return dp[i][j];

	// dp[i][j]에서 갈 수 있는 길 : 2개가 있음
	// dp[maxij + 1][j]와 dp[i][maxij + 1]

	int route1 = INF, route2 = INF;
	int maxij = max(i, j) + 1; 

	// 1번 길
	if(i == 0){ 
		route1 = min(route1, dist(arr[maxij], {1, 1}));
	}
	else{
		route1 = min(route1, dist(arr[maxij], arr[i]));
	}
	route1 += dfs(maxij, j);
	
	// 2번 길
	if(j == 0){
		route2 = min(route2, dist(arr[maxij], {N, N}));
	}
	else{
		route2 = min(route2, dist(arr[maxij], arr[j]));
	}
	route2 += dfs(i, maxij);

	dp[i][j] = min(route1, route2);

	return dp[i][j];
}


void reconstruct(int i, int j){
	// dfs + dp를 보자.
	if(i == W || j == W){ // 둘 중 하나라도 끝에 도달한 경우 더 이상 탐색 필요 없음.
		return;
	}

	// dp[i][j]에서 갈 수 있는 길 : 2개가 있음
	// dp[maxij + 1][j]와 dp[i][maxij + 1]
	int route1 = INF, route2 = INF;
	int maxij = max(i, j) + 1;
	if(i == 0){
		route1 = min(route1, dist(arr[maxij], {1, 1}));
	}
	else{
		route1 = min(route1, dist(arr[maxij], arr[i]));
	}
	route1 += dp[maxij][j];
	

	if(j == 0){
		route2 = min(route2, dist(arr[maxij], {N, N}));
	}
	else{
		route2 = min(route2, dist(arr[maxij], arr[j]));
	}
	route2 += dp[i][maxij];

	// 무조건 탐색 종료까지 남은 길이 짧은 쪽으로 감. 이게 optimal이기 때문
	if(route1 > route2){
		trackback[maxij] = 2;
		reconstruct(i, maxij);
	}
	else{
		trackback[maxij] = 1;
		reconstruct(maxij, j);
	}
}

void solve(){
	cin>>N>>W;
	arr.resize(W+1);
	dp.resize(W+1);
	for(int i = 0; i<=W; i++){
		dp[i].resize(W+1);
		fill(dp[i].begin(), dp[i].end(), INF);
	}
	trackback.resize(W+1);

	for(int i = 1; i<=W; i++){
		cin>>arr[i].first>>arr[i].second;
	}
	for(int i = 0; i<=W; i++){
		for(int j = 0; j<=W; j++){
			dp[i][j] = INF;
		}
	}

	cout<<dfs(0, 0)<<'\n';
	reconstruct(0, 0);
	for(int i = 1; i<=W; i++){
		cout<<trackback[i]<<'\n';
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