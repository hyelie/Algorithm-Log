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

typedef pair<int, char> pic;

int D(int n){
	return (2*n) % 10000;
}
int S(int n){
	if(n == 0) return 9999;
	else return n-1;
}
int L(int n){
	return (n % 1000) * 10 + (n / 1000);
}
int R(int n){
	return n / 10 + (n % 10) * 1000;
}

void solve(){
	int A, B; cin>>A>>B;
	int INF = 987654321;
	vector<int> dp(10000, INF);
	vector<pic> prev(10000);
	dp[A] = 0;
	queue<int> q; q.push(A);
	while (!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == B){
			break;
		}
		int d = D(cur), s = S(cur), l = L(cur), r = R(cur);
		if(dp[d] == INF){
			dp[d] = dp[cur] + 1;
			prev[d] = {cur, 'D'};
			q.push(d);
		}
		if(dp[s] == INF){
			dp[s] = dp[cur] + 1;
			prev[s] = {cur, 'S'};
			q.push(s);
		}
		if(dp[l] == INF){
			dp[l] = dp[cur] + 1;
			prev[l] = {cur, 'L'};
			q.push(l);
		}
		if(dp[r] == INF){
			dp[r] = dp[cur] + 1;
			prev[r] = {cur, 'R'};
			q.push(r);
		}
	}

	int min_dist = dp[B];
	vector<char> trackback(min_dist);
	while(min_dist--){
		trackback[min_dist] = prev[B].second;
		B = prev[B].first;
	}
	for(char elem : trackback) cout<<elem;
	cout<<'\n';
	
	
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
