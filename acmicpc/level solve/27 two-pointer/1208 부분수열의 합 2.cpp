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
meet in the middle
주어진 n으로 Brute-Force는 불가능 해 보이지만,
n/2로 Brute-Force는 가능해 보일 때 사용하는 기법
앞 절반, 뒤 절반으로 나누고 앞 절반으로 뒤 절반을 탐색하면 된다.
(2^(n/2))
*/

void getSum(int cur_depth, int max_depth, vector<int>& arr, int cur_sum, vector<int>& sums){
	if(cur_depth == max_depth){
		sums.push_back(cur_sum);
		return;
	}

	getSum(cur_depth + 1, max_depth, arr, cur_sum, sums);
	getSum(cur_depth + 1, max_depth, arr, cur_sum + arr[cur_depth], sums);
}

void solve(){
	int N, S; cin>>N>>S;
	vector<int> arr1, arr2;
	int input;
	for(int i = 0; i<N; i++){
		cin>>input;
		if(i < N/2){
			arr1.push_back(input);
		}
		else{
			arr2.push_back(input);
		}
	}

	vector<int> sum1;
	getSum(0, N/2, arr1, 0, sum1); // 앞 절반
	vector<int> sum2;
	getSum(0, N - N/2, arr2, 0, sum2); // 뒤 절반

	/*map<int, int> cnt;
	for(int s2 : sum2){
		if(cnt.find(s2) == cnt.end()){
			cnt[s2] = 1;
		}
		else{
			cnt[s2]++;
		}
	}

	ll answer = 0;
	for(int s1 : sum1){
		if(cnt.find(S - s1) != cnt.end()){
			answer += (ll)cnt[S - s1];
		}
	}
	if(S == 0) answer--;
	cout<<answer;*/

	// 뒤 절반 정렬 후 앞 절반으로 탐색	
	// subset size : 2^(n/2)
	// 정렬에 2^(n/2) n/2
	// 각 탐색에 n/2, 원소 2^(n/2)개
	// subset 구하는 것은 잡아먹히고, 2^(n/2) * n/2만 남음.
	sort(sum2.begin(), sum2.end(), less<int>());

	ll answer = 0;
	for(int s1 : sum1){
		answer += (upper_bound(sum2.begin(), sum2.end(), S - s1) - lower_bound(sum2.begin(), sum2.end(), S-s1));
	}
	
	if(S == 0) answer--;
	cout<<answer;

	
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}