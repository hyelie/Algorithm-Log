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
	
	vector<ll> stair_nums(10, 1);
	stair_nums[0] = 0;
	int MOD = 1000000000;

	int n; cin>>n;
	for(int i = 1; i<n; i++){
		vector<ll> temp_stair_nums(10, 0);
		temp_stair_nums[0] = stair_nums[1];
		for(int j = 1; j<=8; j++){
			temp_stair_nums[j] = (stair_nums[j-1] + stair_nums[j+1]) % MOD;
		}
		temp_stair_nums[9] = stair_nums[8];

		for(int j = 0; j<=9; j++){
			stair_nums[j] = temp_stair_nums[j];
		}
	}

	ll sum = 0;
	for(int i = 0; i<=9; i++){
		sum = (sum + stair_nums[i]) % MOD;
	}
	cout<<sum;

	//////////////////////

	return 0;
}