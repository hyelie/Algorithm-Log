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
	
	ll N, M; cin>>N>>M;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];
	sort(arr.begin(), arr.end());

	ll start = 0, end = 2000000001, mid;

	// 최대한 큰 값을 찾는 것이 목표
	while(start < end){
		mid = (start + end) / 2;
		ll sum = 0;
		for(int th : arr){
			if(th > mid) sum += (th - mid);
		}

		if(sum < M){ // 결과물을 더 늘여야 함 (자르는 길이를 줄여야 함)
			end = mid;
		}
		else{
			start = mid + 1;
		}
	}
	cout<<end - 1;

	//////////////////////

	return 0;
}