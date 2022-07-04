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

vector<int> nums;
int N, M; 

void dCombination(int cur_depth, int max_depth, int prev_idx, vector<int>& result){
	if(cur_depth == max_depth){
		for(int i : result) cout<<i<<' ';
		cout<<'\n';
		return;
	}
	for(int i = prev_idx; i<N; i++){
		result[cur_depth] = nums[i];
		dCombination(cur_depth + 1, max_depth, i, result);
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	cin>>N>>M;
	for(int i = 1; i<=N; i++){
		nums.push_back(i);
	}
	vector<int> result(M);

	dCombination(0, M, 0, result);


	//////////////////////

	return 0;
}