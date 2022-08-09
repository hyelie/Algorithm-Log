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
typedef pair<string, bool> psb;

void solve(){
	int N; cin>>N;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];

	// dp initialize
	vector<vector<int>> dp(N, vector<int>(N, 0));
	for(int i = 0; i<N; i++){ // size 1 == 무조건 true
		dp[i][i] = true;
	}
	for(int i = 0; i<N-1; i++){ // size 2 == 같아야 true
		if(arr[i] == arr[i+1]) dp[i][i+1] = 1;
	}

	// dp
	for(int diff = 2; diff<N; diff++){ // 대각선 개수
		for(int r = 0; r<N-diff; r++){ // 한 대각선 당 채울 row 개수
			if(dp[r+1][r+diff-1] == 1 && (arr[r] == arr[r+diff])) dp[r][r+diff] = 1;
			// dp[r][r+diff]를 보면 됨
			
		}
	}

	/*

	0, 0	0, 1	0, 2	0, 3	0, 4
	    	1, 1	1, 2	1, 3	1, 4
		      		2, 2	2, 3	2, 4
					  		3, 3	3, 4
							  		4, 4

	// dp[r][c]를 볼 때, 좌로1칸 아래로 1칸(r+1~c-1)이 팰린드롬이고 arr[r]과 arr[c]가 같으면 팰린드롬.
	*/

	int M; cin>>M;
	while(M--){
		int S, E; cin>>S>>E;
		cout<<dp[S-1][E-1]<<'\n';
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	solve();

	//////////////////////

	return 0;
}