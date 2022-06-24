#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;
int board_size = 8;

void solve(){
	vector<string> board(board_size);
	vector<int> num_hash(board_size, 0);
	for(int i = 0; i<board_size; i++){
		cin>>board[i];
		for(int j = 0; j<board_size; j++){
			if(board[i][j] == '#') num_hash[i]++;
		}
	}

	for(int i = 1; i<=7; i++){
		if(num_hash[i-1] == 2 && num_hash[i+1] == 2 && num_hash[i] == 1){
			cout<<i+1<<' ';
			for(int j = 0; j<board_size; j++){
				if(board[i][j] == '#'){
					cout<<j+1<<'\n';
					return;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}