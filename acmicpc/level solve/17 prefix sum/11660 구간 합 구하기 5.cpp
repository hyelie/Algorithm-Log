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

int getRangeSum(vector<vector<int>>& psum, int x1, int y1, int x2, int y2){
	int result = psum[x2][y2];
	if(x1 != 0) result -= psum[x1 - 1][y2];
	if(y1 != 0) result -= psum[x2][y1 - 1];
	if(x1 != 0 && y1 != 0) result += psum[x1 - 1][y1 - 1];
	return result;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N, M; cin>>N>>M;
	vector<vector<int>> board(N, vector<int>(N)), psum(N+1, vector<int>(N+1, 0));

	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cin>>board[i][j];
		}
	}

	psum[0][0] = board[0][0];
	for(int r = 1; r<=N; r++){
		for(int c = 1; c<=N; c++){
			psum[r][c] = board[r-1][c-1] + psum[r-1][c] + psum[r][c-1] - psum[r-1][c-1];
		}
	}

	int x1, y1, x2, y2;
	while(M--){
		cin>>x1>>y1>>x2>>y2;
		cout<<getRangeSum(psum, x1, y1, x2, y2)<<'\n';
	}

	//////////////////////

	return 0;
}