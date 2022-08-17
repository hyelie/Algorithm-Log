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

void solve(){
	int N; cin>>N;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];
	sort(arr.begin(), arr.end(), less<int>());

	pii answer = {1000000000, 1000000000};

	int s = 0, e = N-1, cur_sum;
	while(s < e){
		cur_sum = arr[s] + arr[e];
		if(abs(cur_sum) < abs(answer.first + answer.second)){
			answer = {arr[s], arr[e]};
		}

		if(cur_sum > 0){
			e--;
		}
		else if(cur_sum < 0){
			s++;
		}
		if(cur_sum == 0) break;
	}
	cout<<answer.first<<' '<<answer.second;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}