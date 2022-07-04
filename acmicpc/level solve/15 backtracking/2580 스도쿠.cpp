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

int boardsize = 9;
int board[9][9], ncount[10];
vector<pii> zeros;

void clearNCount(){
	for(int i = 1; i<=boardsize; i++) ncount[i] = 0;
}

bool putable(pii p){
	int row = p.first, col = p.second;

	clearNCount();
	for(int c = 0; c<boardsize; c++){
		ncount[board[row][c]]++;
		if(board[row][c] != 0 && ncount[board[row][c]] >= 2) return false;
	}

	clearNCount();
	for(int r = 0; r<boardsize; r++){
		ncount[board[r][col]]++;
		if(board[r][col] != 0 && ncount[board[r][col]] >= 2) return false;
	}

	int rowblock = row/3 * 3, colblock = col/3 * 3;
	clearNCount();
	for(int r = rowblock; r<rowblock + 3; r++){
		for(int c = colblock; c <colblock + 3; c++){
			ncount[board[r][c]]++;
			if(board[r][c] != 0 && ncount[board[r][c]] >= 2) return false;
		}
	}

	return true;
}

bool backtrack(int cur_depth, int max_depth){
	if(cur_depth == max_depth){
		for(int r = 0; r<boardsize; r++){
			for(int c =0; c<boardsize; c++){
				cout<<board[r][c]<<' ';
			}
			cout<<'\n';
		}
		return true;
	}

	pii cur_p = zeros[cur_depth];
	for(int i = 1; i<=boardsize; i++){
		board[cur_p.first][cur_p.second] = i;
		if(putable(cur_p)){
			bool result = backtrack(cur_depth + 1, max_depth);
			if(result) return true;
		}
		board[cur_p.first][cur_p.second] = 0;
	}

	return false;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	for(int r = 0; r<boardsize; r++){
		for(int c = 0; c<boardsize; c++){
			cin>>board[r][c];
			if(board[r][c] == 0){
				zeros.push_back({r, c});
			}
		}
	}

	backtrack(0, zeros.size());

	//////////////////////

	return 0;
}