#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
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
	vector<int> arr(N), LIS, dp(N, 0);
	// arr : 입력 vector
	// LIS : LIS의 길이를 구할 vector
	// dp : arr[i]가 마지막 element일 때, LIS의 max length vector
	for(int i = 0; i<N; i++){
		cin>>arr[i];
	}

	LIS.push_back(arr[0]);
	dp[0] = 1;
	for(int i = 1; i<N; i++){
		if(LIS.back() < arr[i]){ // LIS를 늘일 수 있는 경우
			LIS.push_back(arr[i]); // LIS 배열 제일 뒤에 해당 값을 넣고
			dp[i] = LIS.size(); // dp는 해당 값으로 넣음
		}
		else{ // LIS 중간에 넣는 경우
			int idx = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin(); // 넣을 위치 찾고
			LIS[idx] =arr[i]; // 해당 값 갱신()
			dp[i] = idx + 1; // arr[i]를 마지막으로 가지는 LIS의 max length : idx + 1
		}
	}

	int answer = LIS.size();
	cout<<answer<<'\n';
	stack<int> stk;
	for(int i = N-1; i>=0; i--){ // dp 배열에서 뒤에서부터 가져옴
		if(dp[i] == answer){
			stk.push(arr[i]);
			answer--;
		}
	}

	while(!stk.empty()){
		cout<<stk.top()<<' ';
		stk.pop();
	}

	

	//////////////////////

	return 0;
}