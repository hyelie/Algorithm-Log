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
	vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
	// dp[i][j] : A는 i까지, B는 j까지 봤을 때 LCS
	for(int c = 0, isMatch = 0; c<B.size(); c++){
		if(A[0] == B[c]){
			isMatch = 1;
		}
		dp[0][c] = isMatch;
	}
	for(int r = 0, isMatch = 0; r<A.size(); r++){
		if(A[r] == B[0]){
			isMatch = 1;
		}
		dp[r][0] = isMatch;
	}

	for(int r = 1; r<A.size(); r++){
		for(int c = 1; c<B.size(); c++){
			dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
			if(A[r] == B[c]){
				dp[r][c] = dp[r-1][c-1] + 1;
			}
		}
	}

	int cnt = dp[A.size()-1][B.size()-1];
	cout<<cnt<<'\n';

	int r = A.size()-1, c = B.size()-1;
	vector<char> answer(cnt);
	while(dp[r][c] != 0 && cnt >= 1){
		while(r > 0 && dp[r-1][c] == dp[r][c]){
			r--;
		}
		while(c > 0 && dp[r][c-1] == dp[r][c]){
			c--;
		}
		//if(r > 0 && c > 0 && dp[r][c] > dp[r-1][c-1]){
			answer[cnt-1] = A[r];
			cnt--;
			if(r>0) r--; 
			if(c>0) c--;
		//}
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