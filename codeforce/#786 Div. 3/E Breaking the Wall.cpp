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

/*
경우의 수
완전 별개의 2개 벽을 부수는 경우
	하나 부수는데 ceil(ai/2)
	-> ceil(ai/2) + ceil(aj/2)
연속된 2개 벽을 부수는 경우 type2
	한번 쏘는 데 평균적 3딜 줌(둘 다 있을 때)
	하나 없으면 2딜 줌
	-> 최대한 고루 때려야 함
	-> ceil((ai+aj)/3)
	다만 고루 떄려도 남는 경우. 2 * ai < aj와 같은 경우
	-> aj만 때려도 ai 사라짐
	-> ceil(aj/2)
사이에 1칸 있는 2개 벽을 부수는 경우 type3
	가운데 쏘면 양쪽에 1씩, 한쪽에 쏘면 [2, 0]이 들어감
	-> ceil((ai + aj) / 2)
*/

int n, INF = 1000000000;
vector<int> arr;

int type1(){
	vector<int> nums(n);
	for(int i = 0; i<n; i++){
		nums[i] = (int)ceil((double)arr[i] / 2);
	}
	sort(nums.begin(), nums.end(), less<int>());
	return nums[0] + nums[1];
}

int type2(){
	int min_value = INF;
	for(int i = 0; i<n-1; i++){
		int x = arr[i], y = arr[i+1];
		if(x > y){ // after swap, x <= y
			int temp = x;
			x = y;
			y = temp;
		}
		if(2 * x < y){
			min_value = min(min_value, (int)ceil((double)y / 2));
		}
		else{
			min_value = min(min_value, (int)ceil((double)(x + y)/3));
		}
	}
	return min_value;
}

int type3(){
	int min_value = INF;
	for(int i = 1; i<n-1; i++){
		int x = arr[i-1], y = arr[i+1];
		min_value = min(min_value, (int)ceil((double)(x+y)/2));
	}
	return min_value;
}

void solve(){
	cin>>n;
	arr.resize(n);
	for(int i = 0; i<n; i++) cin>>arr[i];

	int result = INF;
	int a = type1(), b = type2(), c = type3();
	result = min(result, a);
	result = min(result, b);
	result = min(result, c);
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