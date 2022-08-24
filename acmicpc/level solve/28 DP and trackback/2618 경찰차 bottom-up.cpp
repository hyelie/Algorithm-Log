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
void solve(){
	int N, W; cin>>N>>W;
	vector<pii> arr(W+1);
	for(int i = 1; i<=W; i++){
		cin>>arr[i].first>>arr[i].second;
	}
	int INF = 987654321;
	vector<vector<int>> dp(W+1, vector<int>(W+1, INF));
	vector<vector<pii>> prev(W+1, vector<pii>(W+1, {-1, -1}));
	
	dp[0][0] = 0;
	dp[1][0] = dist({1, 1}, arr[1]); prev[1][0] = {0, 0};
	dp[0][1] = dist({N, N}, arr[1]); prev[0][1] = {0, 0};
	for(int i = 0; i<=W; i++){
		for(int j = 0; j<=W; j++){
			if(i == j) continue;
			int maxij = max(i, j) + 1;
			if(maxij > W) continue;
			
			int route1;
			if(i == 0){
				route1 = dist({1, 1}, arr[maxij]);	
			}
			else{
				route1 = dist(arr[i], arr[maxij]);	
			}
			route1 += dp[i][j];
			if(dp[maxij][j] > route1){
				dp[maxij][j] = route1;
				prev[maxij][j] = {i, j};
			}
			
			int route2;
			if(j == 0){
				route2 = dist({N, N}, arr[maxij]);	
			}
			else{
				route2 = dist(arr[j], arr[maxij]);
			}
			route2 += dp[i][j];
			if(dp[i][maxij] > route2){
				dp[i][maxij] = route2;
				prev[i][maxij] = {i, j};
			}
		}
	}
	
	pii answer_prev;
	int answer = INF;
	for(int i = 0; i<W; i++){
		if(answer > dp[i][W]){
			answer = dp[i][W];
			answer_prev = {i, W};
		}
		if(answer > dp[W][i]){
			answer = dp[W][i];
			answer_prev = {W, i};
		}
	}
	
	cout<<answer<<'\n';
	vector<int> trackback(W);
	while(W--){
		pii temp = prev[answer_prev.first][answer_prev.second];
		if(temp.first == answer_prev.first){
			trackback[W] = 2;
		}
		else trackback[W] = 1;
		answer_prev = temp;
	}
	
	for(int elem : trackback){
		cout<<elem<<'\n';
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