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
	
	int N; cin>>N;
	int MOD = 15746;
	vector<int> arr(N+1, 0);
	arr[1] = 1; arr[2] = 2;
	for(int i = 3; i<=N; i++){
		arr[i] = (arr[i-2] + arr[i-1]) % MOD;
	}
	cout<<arr[N];


	//////////////////////

	return 0;
}

/*
1
1

2
00, 11

3
001, 111, 100

4
0011, 1111, 1001, 0000, 1100

dp[i-2] + dp[i]
*/