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

int qp[15]; // qp[i] : column of queen on i'th row
int N, answer = 0;; 

bool attackable(pii a, pii b){
	if(a.first == b.first || a.second == b.second) return true;
	else if(abs(a.first - b.first) == abs(a.second - b.second)) return true;
	return false;
}

bool available(pii p){
	for(int i = 0; i<p.first; i++){
		if(attackable({i, qp[i]}, p)) return false;
	}
	return true;
}

void backtrack(int cur_depth, int max_depth){
	if(cur_depth == max_depth){
		answer++;
		return;
	}
	for(int i = 0; i<N; i++){
		if(available({cur_depth, i})){
			qp[cur_depth] = i;
			backtrack(cur_depth+1, max_depth);
		}
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	cin>>N;
	backtrack(0, N);
	cout<<answer;

	//////////////////////

	return 0;
}