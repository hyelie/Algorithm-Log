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

int timeToInt(int H, int M){
	return 60 * H + M;
}

pii intToTime(int t){
	return {(t/60)%24, t%60};
}

void solve(){
	int n, H, M; cin>>n>>H>>M;
	int startTime = timeToInt(H, M);
	int hi, mi;
	vector<int> minutes(n);
	for(int i = 0; i<n; i++){
		cin>>hi>>mi;
		minutes[i] = timeToInt(hi, mi);
		if(minutes[i] < startTime) minutes[i] += 1440;
	}
	sort(minutes.begin(), minutes.end());
	int result = *lower_bound(minutes.begin(), minutes.end(), timeToInt(H, M)) - startTime;
	pii answer = intToTime(result);
	cout<<answer.first<<' '<<answer.second<<'\n';
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}