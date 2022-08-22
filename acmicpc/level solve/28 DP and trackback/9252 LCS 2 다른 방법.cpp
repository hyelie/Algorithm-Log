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
	string A, B; cin>>A>>B;
	vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
	// dp[i][j] : A는 i까지, B는 j까지 봤을 때 LCS
	for(int r = 1; r<=A.size(); r++){
		for(int c = 1; c<=B.size(); c++){
			dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
			if(A[r-1] == B[c-1]){
				dp[r][c] = dp[r-1][c-1] + 1;
			}
		}
	}

	/int cnt = dp[A.size()][B.size()];
	cout<<cnt<<'\n';

	int r = A.size(), c = B.size();
	vector<char> answer(cnt);
	while(dp[r][c] != 0){
		while(r > 1 && dp[r-1][c] == dp[r][c]){
			r--;
		}
		while(c > 1 && dp[r][c-1] == dp[r][c]){
			c--;
		}
		answer[cnt-1] = A[r-1];
		cnt--;
		r--; c--;
	}
	for(char elem : answer) cout<<elem;
}

/*  ACAYKP
C 011111
A 112222
P 112222
C 122222
A 123333
K 123344
*/
//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}