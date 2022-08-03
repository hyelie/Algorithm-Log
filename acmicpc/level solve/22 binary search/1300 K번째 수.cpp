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
	
	ll N, K; cin>>N>>K;
	ll start = 0, end = 10000000000, mid;

	// 0이 아니라 1부터 시작
	while(start < end){
		mid = (start + end) / 2; // mid : 현재 볼 값
		ll cnt = 0; // cnt : mid보다 작은 index 개수
		for(int i = 1; i<=N; i++){
			cnt += min(mid/i, N);
		}
		if(cnt >= K){ // 더 많은 숫자가 있는 경우 수를 줄여야 함
			end = mid;
		}
		else{
			start = mid + 1;
		}
	}
	cout<<end;

	//////////////////////

	return 0;
}