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

// .first : start time, .second : end time
bool cmp(pii&a, pii&b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	string s; cin>>s;
	vector<int> nums;
	vector<bool> op; // op[i] : 1 then +, 0 then -
	int i, prev_i;
	for(i = 0, prev_i = 0; i<s.length(); i++){
		if(!(s[i] == '+' || s[i] == '-')) continue;
		
		op.push_back((s[i] == '+' ? true : false));
		nums.push_back(stoi(s.substr(prev_i, i - prev_i)));
		prev_i = i+1;
	}
	nums.push_back(stoi(s.substr(prev_i)));

	int result = 0;
	for(int i = op.size()-1; i>=0; i--){
		if(op[i]) nums[i] = nums[i+1] + nums[i]; // -가 나올 때 까지 +는 모두 묶음
		else result -= nums[i+1]; // -가 나오면 묶은 것을 result에서 뺌
	}
	result += nums[0]; // 초항을 더함
	cout<<result;

	//////////////////////

	return 0;
}
// 55 - 50 + 40
// 최소로 하기 위해서는 - 뒤에 있는 것을 모두 묶어야 한다.
// 뒤에서부터 묶으면 된다.