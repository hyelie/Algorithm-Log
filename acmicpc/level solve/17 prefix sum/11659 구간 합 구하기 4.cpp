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

// return partial sum
// psum[i] : sum from index 0 to index i
vector<int> setPsum(vector<int>& arr){
	vector<int> psum(arr.size());
	psum[0] = arr[0];

	for(int i = 1; i<arr.size(); i++){
		psum[i] = psum[i-1] + arr[i];
	}
	
	return psum;
}

// return range sum from index 'start' to index 'end'
int getRangeSum(vector<int>& psum, int start, int end){
	if(start == 0) return psum[end];
	return psum[end] - psum[start - 1];
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N, M; cin>>N>>M;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];
	vector<int> psum = setPsum(arr);

	int start, end;
	while(M--){
		cin>>start>>end;
		cout<<getRangeSum(psum, start-1, end-1)<<'\n';
	}


	//////////////////////

	return 0;
}