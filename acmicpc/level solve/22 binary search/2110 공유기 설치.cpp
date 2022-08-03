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
	
	ll N, C; cin>>N>>C;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];
	sort(arr.begin(), arr.end());

	ll start = 0, end = 1000000000, mid;
	while(start < end){
		mid = (start + end) / 2; // mid : 공유기 사이의 최대 거리
		ll cnt = 1, prev = arr[0];
		for(int i = 1; i<N; i++){
			if(arr[i] - prev >= mid){ // 설치 가능
				prev = arr[i];
				cnt++;
			}
		}

		if(cnt < C){ // 거리가 더 줄어야 함. upper bound로 계산.
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