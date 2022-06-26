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
typedef pair<int, int> pii;

vector<vector<string>> chessboard = {
	{
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	},
	{
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	}
};

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N, M; cin>>N>>M;

	vector<string> input(N);
	for(int i = 0; i<N; i++){
		cin>>input[i];
	}

	int min_value = 65;
	
	for(int r = 0; r<=N-8; r++) {
		for(int c = 0; c<=M-8; c++){
			for(int t = 0; t<2; t++){
				int num_diff = 0;
				for(int rr = 0; rr<8; rr++){
					for(int cc = 0; cc<8; cc++){
						if(chessboard[t][rr][cc] != input[r + rr][c + cc]) num_diff++;
					}
				}
				min_value = min(min_value, num_diff);
			}
		}
	}
	cout<<min_value;

	return 0;
}