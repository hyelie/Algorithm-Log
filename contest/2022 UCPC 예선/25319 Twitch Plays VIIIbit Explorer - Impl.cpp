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

void mv(pii from, pii to, string& command){
	string ud_char = "U";
	int ud_value = to.first - from.first;
	if(ud_value > 0) ud_char = "D"; // 아래로 가야 함

	string lr_char = "L";
	int lr_value = to.second - from.second;
	if(lr_value > 0) lr_char = "R"; // 오른쪽으로 가야 함
		
	for(int r = 0; r<abs(ud_value); r++) command += ud_char;
	for(int c = 0; c<abs(lr_value); c++) command += lr_char;
	
	return;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	int N, M, s_len; 
	cin>>N>>M>>s_len;

	vector<string> board(N);
	vector<set<pii>> board_cnt(29);
	for(int i = 0; i<N; i++){
		cin>>board[i];
		for(int j = 0; j<M; j++){
			board_cnt[board[i][j]-'a'].insert({i, j});
		}
	}

	string target_id; 
	cin>>target_id;
	vector<int> id_cnt(28);
	for(char c : target_id){
		id_cnt[c-'a']++;
	}

	int C = 99999999;
	for(int i = 0; i<28; i++){
		if(id_cnt[i] == 0){
			continue;
		}
		C = min(C, (int)board_cnt[i].size()/id_cnt[i]);
	}

	pii cur_p = {0, 0};
	string max_command = "";
	for(int i = 0; i<C; i++){
		for(int si = 0; si < target_id.size(); si++){
			pii si_p = *(board_cnt[target_id[si] - 'a'].begin());
			board_cnt[target_id[si] - 'a'].erase(si_p);
			mv(cur_p, si_p, max_command);
			max_command += "P";
			cur_p = si_p;
		}
	}
	mv(cur_p, {N-1, M-1}, max_command);

	cout<<C<<' '<<max_command.size()<<'\n';
	cout<<max_command<<'\n';

	//////////////////////

	return 0;
}

