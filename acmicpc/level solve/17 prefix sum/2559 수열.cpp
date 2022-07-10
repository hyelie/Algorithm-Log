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

ll getRangeSum(vector<ll>& psum, ll start, ll end){
	if(start == 0) return psum[end];
	return psum[end] - psum[start - 1];
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	// solved by partial sum
	/*ll N, K; cin>>N>>K;
	vector<ll> arr(N), psum(N);
	for(ll i = 0; i<N; i++){
		cin>>arr[i];
	}
	psum[0] = arr[0];
	for(ll i = 1; i<N; i++){
		psum[i] = psum[i-1] + arr[i];
	}

	ll answer = -20000000000;
	for(ll i = 0; i<N-K+1; i++){
		answer = max(answer, getRangeSum(psum, i, i+K-1));
	}

	cout<<answer;*/

	// solved by sliding window
	ll N, K; cin>>N>>K;
	vector<ll> arr(N);
	for(ll i = 0; i<N; i++){
		cin>>arr[i];
	}

	ll start = 0, end = start + K - 1, answer, window = 0;

	for(int i = 0; i<=end; i++) window += arr[i];
	answer = window;

	for(start = 0, end = K-1; end < N-1; start++, end++){
		window += arr[end+1] - arr[start];
		answer = max(answer, window);
	}
	cout<<answer;



	/*
	tp을 이용해 합이 최대가 되는 구간;;
	int answer = -1;
	int start = 0, end = 0;
	while(start < N && end < N){
		int cur_sum = getRangeSum(psum, start, end);
		answer = max(cur_sum, answer);
		if(cur_sum < 0) start++;
		else end++;
		if(start > end) end = start;
	}*/

	


	//////////////////////

	return 0;
}