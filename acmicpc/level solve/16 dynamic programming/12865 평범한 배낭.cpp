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
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N, K; cin>>N>>K;

	vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
	// dp[i][j] : i개의 물건을 봤을 때, 무게 j만큼 들 때 최대 가치
	
	vector<pii> things(N+1);
	// .first : 무게, .second : 가치
	for(int i = 1; i<=N; i++){
		cin>>things[i].first>>things[i].second;
	} 

	for(int n = 1; n<=N; n++){
		for(int w = 1; w<=K; w++){
			if(w >= things[n].first){
				// 전자 : i번째 물건을 담지 않음, 후자 : i번째 물건을 담음
				dp[n][w] = max(dp[n-1][w], dp[n-1][w-things[n].first] + things[n].second);
			}
			else dp[n][w] = dp[n-1][w];
		}
	}

	cout<<dp[N][K];


	//////////////////////

	return 0;
}