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

int maxn = 3*3*3*3*3*3*3;
vector<vector<int>> board(maxn, vector<int>(maxn));
vector<int> answer(3, 0);

void recurse(int r, int c, int length){
	vector<int> cnt(3, 0);
	for(int i = r; i<r + length; i++){
		for(int j = c; j<c+length; j++){
			cnt[board[i][j]+1]++; // -1 -> 0, 0 -> 1, 1 -> 2
		}
	}

	for(int i = 0; i<3; i++){
		if(cnt[i] == length * length){
			answer[i]++;
			return;
		}
	}

	int nextlen = length/3;
	recurse(r, c, nextlen);
	recurse(r, c + nextlen, nextlen);
	recurse(r, c + 2 * nextlen, nextlen);
	recurse(r + nextlen, c, nextlen);
	recurse(r + nextlen, c + 2 * nextlen, nextlen);
	recurse(r + nextlen, c + nextlen, nextlen);
	recurse(r + 2 * nextlen, c, nextlen);
	recurse(r + 2 * nextlen, c + nextlen, nextlen);
	recurse(r + 2 * nextlen, c + 2 * nextlen, nextlen);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cin>>board[i][j];
		}
	}

	recurse(0, 0, N);
	for(int i = 0; i<3; i++){
		cout<<answer[i]<<'\n';
	}

	//////////////////////

	return 0;
}