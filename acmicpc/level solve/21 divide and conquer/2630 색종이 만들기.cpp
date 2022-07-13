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

int N, num_blue = 0, num_white = 0;
int board[128][128];

void recurse(int length, int r, int c){
	int cnt = 0;
	for(int i = r; i<r+length; i++){
		for(int j = c; j<c+length; j++){
			if(board[i][j]) cnt++;
		}
	}
	if(cnt == 0){
		num_white++;
		return;
	}
	else if(cnt == length * length){
		num_blue++;
		return;
	}
	recurse(length/2, r, c);
	recurse(length/2, r + length/2, c);
	recurse(length/2, r, c + length/2);
	recurse(length/2, r + length/2, c + length/2);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	cin>>N;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cin>>board[i][j];
		}
	}

	recurse(N, 0, 0);

	cout<<num_white<<'\n'<<num_blue;
	

	//////////////////////

	return 0;
}