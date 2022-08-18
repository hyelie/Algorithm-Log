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

int N, C;
vector<int> arr;

void dfs(int cur_depth, int max_depth, int value, vector<int>& result){
	if(cur_depth == max_depth){
		result.push_back(value);
		return;
	}

	dfs(cur_depth+1, max_depth, value, result);
	if(value + arr[cur_depth] <= C){ // pruning
		dfs(cur_depth+1, max_depth, value + arr[cur_depth], result);
	}
	
}

void solve(){
	cin>>N>>C;
	arr.resize(N);
	for(int i = 0; i<N; i++) cin>>arr[i];

	// meet in the middle
	vector<int> arr1, arr2;
	dfs(0, N/2, 0, arr1); // 앞 부분
	dfs(N/2, N, 0, arr2); // 뒷 부분

	// 뒷 부분 정렬 : 2^(n/2) * n/2
	sort(arr2.begin(), arr2.end(), less<int>());

	// 탐색 : 2^(n/2) * log(2^(n/2)) = 2^(n/2) * n/2
	ll result = 0;
	for(int a1 : arr1){
		result += (upper_bound(arr2.begin(), arr2.end(), C - a1) - arr2.begin());
	}
	cout<<result;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}