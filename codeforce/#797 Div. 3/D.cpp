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
int INF = 1000000000;

void solve(){

	int n, k; // k개의 연속된 것이 black이기 위해서 몇개를 칠해야 하는지의 min값
	cin>>n>>k;
	string s; cin>>s;
	// sliding window

	int num_white = 0;
	for(int i = 0; i<k; i++){
		if(s[i] != 'B') num_white++;
	}
	int min_value = num_white; 

	for(int i = 0; i<n-k; i++){
		if(s[i+k] == 'W') num_white++;
		if(s[i] == 'W') num_white--;
		min_value = min(min_value, num_white);
	}
	cout<<min_value<<'\n';
	return;
}

int main(void) {
	// cin.tie(0);
	// cout.tie(0);
	// std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}



	//////////////////////

	return 0;
}

/*
si : 시간
fi : task 끝난 시간
di : task execution time
task는 온 순서대로 끝난다

task를 끝내기 전에 new가 오면 queue의 끝에 넣는다
queue 순서로 일을 한다.
di를 찾아라

0 3 7
2 10 11
2 7 1

음...
10 15
11 16
1 1

12 16 90 195 1456 1569 3001 5237 19275
13 199 200 260 9100 10000 10914 91066 5735533
1 

q에 start time push
cur time = start time
모든 i 순회
	s[i] <= cur time then push that job from queue with cur time
	f[i] >= cur time then pop that job from queue, calculate working time(cur time - input cur time);

	if queue empty then cur_time = min(s[i+1], f[i])
*/