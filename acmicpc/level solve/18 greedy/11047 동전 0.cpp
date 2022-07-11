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
	
	int N, K; cin>>N>>K;
	vector<int> coins(N);
	for(int i = 0; i<N; i++)cin>>coins[i];
	sort(coins.begin(), coins.end(), greater<int>());
	int answer = 0;
	for(int i = 0; i<N; i++){
		answer += K/coins[i];
		K %= coins[i];
	}
	cout<<answer;

	//////////////////////

	return 0;
}