#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
vector<vector<char>> board;

void recurse(int len, int sr, int sc){
	if(len == 3){
		for(int r = sr; r<sr + 3; r++){
			for(int c= sc; c<sc+3; c++){
				board[r][c] = '*';
			}
		}
		board[sr+1][sc+1] = ' ';
		return;
	}

	int next_len = len/3;
	recurse(next_len, sr, sc);
	recurse(next_len, sr, sc + next_len);
	recurse(next_len, sr, sc + 2 * next_len);
	recurse(next_len, sr + next_len, sc);
	recurse(next_len, sr + next_len, sc + 2 * next_len);
	recurse(next_len, sr + 2 * next_len, sc);
	recurse(next_len, sr + 2 *next_len, sc + next_len);
	recurse(next_len, sr + 2 *next_len, sc + 2 * next_len);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N; cin>>N;
	vector<vector<char>> boards(N, vector<char>(N, ' '));
	board = boards;

	recurse(N, 0, 0);

	for(int r = 0; r<N; r++){
		for(int c = 0; c<N; c++){
			cout<<board[r][c];
		}cout<<'\n';
	}

	return 0;
}