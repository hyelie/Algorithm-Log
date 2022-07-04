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

int N; 
int board[21][21];
int min_diff = 2000000000;
bool isInStart[21];
int teamStart[21], teamLink[21];

int calPoint(int team[]){
	int point = 0;
	for(int i = 0; i<N/2; i++){
		for(int j = i+1; j<N/2; j++){
			point += board[team[i]][team[j]] + board[team[j]][team[i]];
		}
	}
	return point;
}

void backtrack(int cur_depth, int max_depth, int prev_idx){
	if(cur_depth == max_depth){
		int team_start_idx = 0, team_link_idx = 0;
		for(int i = 0; i<N; i++){
			if(isInStart[i]) teamStart[team_start_idx++] = i;
			else teamLink[team_link_idx++] = i;
		}
		int result = abs(calPoint(teamStart) - calPoint(teamLink));
		min_diff = min(min_diff, result);
		return;
	}

	for(int i = prev_idx + 1; i<N; i++){
		isInStart[i] = true;
		backtrack(cur_depth + 1, max_depth, i);
		isInStart[i] = false;
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	cin>>N;
	for(int r = 0; r<N; r++){
		for(int c = 0; c<N; c++){
			cin>>board[r][c];
		}
	}
	for(int i = 0; i<N; i++) isInStart[i] = false;
	backtrack(0, N/2, -1);

	cout<<min_diff;

	//////////////////////

	return 0;
}