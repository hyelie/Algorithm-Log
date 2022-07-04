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

int N, M, s_len; 
vector<string> boards;
string target_id; 

int C = -1;
string max_command = "";

vector<int> id_cnt(28, 0), board_cnt(28, 0);

bool DFS(int cur_depth, pii cur_p, string command){
	bool flag = true;
	for(int i = 0; i<28; i++){
		if(id_cnt[i] != 0 && board_cnt[i] < id_cnt[i]){
			flag = false;
			break;
		}
	}

	char target_char = target_id[cur_depth % s_len];
	if(!flag){ // 더 못찾는 경우
		for(int r = cur_p.first; r<N-1; r++) command += "D";
		for(int c = cur_p.second; c<M-1; c++) command += "R";
		if(command.length() > 1000000) return false;

		int cal_C = cur_depth/s_len;
		if(cal_C == C){
			if(command.length() < max_command.length()){
				max_command = command;
			}
		}
		if(cal_C > C){
			C = cal_C;
			max_command = command;
		}
		return true;
	}


	vector<pii> target_v;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			if(boards[i][j] == target_char){
				target_v.push_back({i, j});
			}
		}
	}
	for(pii tar_p : target_v){
		string temp_command = command;
		
		string ud_char = "U";
		int ud_value = tar_p.first - cur_p.first;
		if(ud_value > 0) ud_char = "D"; // 아래로 가야 함

		string lr_char = "L";
		int lr_value = tar_p.second - cur_p.second;
		if(lr_value > 0) lr_char = "R"; // 오른쪽으로 가야 함
		
		for(int r = 0; r<abs(ud_value); r++) temp_command += ud_char;
		for(int c = 0; c<abs(lr_value); c++) temp_command += lr_char;
		
		temp_command += "P";

		if(temp_command.size() > 1000000) continue;

		boards[tar_p.first][tar_p.second] = ' ';
		board_cnt[target_char - 'a']--;
		id_cnt[target_char - 'a']--;
		bool result = DFS(cur_depth + 1, tar_p, temp_command);
		if(result == true) return true;
		boards[tar_p.first][tar_p.second] = target_char;
		board_cnt[target_char - 'a']++;
		id_cnt[target_char - 'a']++;
	}
	return false;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	cin>>N>>M>>s_len;
	vector<string> board(N);
	for(int i = 0; i<N; i++){
		cin>>board[i];
		for(int j = 0; j<M; j++){
			board_cnt[board[i][j]-'a']++;
		}
	}
	boards = board;
	cin>>target_id;

	for(char c : target_id){
		id_cnt[c-'a']++;
	}

	DFS(0, {0, 0}, "");

	cout<<C<<' '<<max_command.size()<<'\n';
	cout<<max_command<<'\n';

	//////////////////////

	return 0;
}

