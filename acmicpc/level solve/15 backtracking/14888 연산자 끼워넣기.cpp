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

int numbers[11], min_value = 2000000000, max_value = -2000000000;
int num_op[4] = {0, 0, 0, 0};

void backtrack(int cur_depth, int max_depth, int value){
	if(cur_depth == max_depth){
		min_value = min(min_value, value);
		max_value = max(max_value, value);
		return;
	}

	if(num_op[0] > 0){
		num_op[0]--;
		backtrack(cur_depth + 1, max_depth, value + numbers[cur_depth+1]);
		num_op[0]++;
	}
	if(num_op[1] > 0){
		num_op[1]--;
		backtrack(cur_depth + 1, max_depth, value - numbers[cur_depth+1]);
		num_op[1]++;
	}
	if(num_op[2] > 0){
		num_op[2]--;
		backtrack(cur_depth + 1, max_depth, value * numbers[cur_depth+1]);
		num_op[2]++;
	}
	if(num_op[3] > 0){
		num_op[3]--;
		backtrack(cur_depth + 1, max_depth, value / numbers[cur_depth+1]);
		num_op[3]++;
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	for(int i = 0; i<N; i++) cin>>numbers[i];
	for(int i = 0; i<4; i++) cin>>num_op[i];
	backtrack(0, N-1, numbers[0]);

	cout<<max_value<<'\n'<<min_value;


	//////////////////////

	return 0;
}