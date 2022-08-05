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

void solve(){
	int s; cin>>s;
	vector<int> result;
	int num = 9;
	while(s != 0){
		if(s - num >= 0){
			s -= num;
			result.push_back(num);
		}
		num--;
	}

	for(int i = result.size()-1; i>=0; i--){
		cout<<result[i];
	}
	cout<<'\n';

	// digit들의 합인 s, 모든 digit은 distinct

	// 큰 수부터 뽑고 정렬하면 되겠군 - 이게 자리수를 제일 덜 먹음
	// 9를 뽑고(안되면 8을 뽑고, ... 안되면 1을 뽑는 식으로)
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}