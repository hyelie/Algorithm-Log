#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

// banned가 user가 될 수 있는지
bool can_ban(string &banned, string &user){
    if(banned.length() != user.length()) return false;
    
    int len = user.length();
    for(int i = 0; i<len; i++){
        if(banned[i] != '*' && banned[i] != user[i]) return false;
    }
    
    return true;
}

set<string> answer;
vector<bool> visited; // [i] : i번째 user를 썼는지 여부
vector<vector<int>> banned_candidates; // [i] : i번째 banned id가 될 수 있는 user id index 목록

void backtrack(int cur_depth, int max_depth, string &result){
    if(cur_depth == max_depth){
        string temp(result.begin(), result.end());
        sort(temp.begin(), temp.end());
        answer.insert(temp);
        return;
    }
    
    for(int candidate : banned_candidates[cur_depth]){
        if(!visited[candidate]){
            visited[candidate] = true;
            result[cur_depth] = candidate + '0';
            backtrack(cur_depth + 1, max_depth, result);
            visited[candidate] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    // init
    vector<vector<int>> _banned_candidates(banned_id.size()); 
    vector<bool> _visited(user_id.size(), false);
    for(int i = 0; i<user_id.size(); i++){
        for(int j = 0; j<banned_id.size(); j++){
            if(can_ban(banned_id[j], user_id[i])){
                _banned_candidates[j].push_back(i);
            }
        }
    }
    banned_candidates = _banned_candidates;
    visited = _visited;
    
    // 모든 경우 backtracking
    string temp = "";
    for(int i = 0; i<banned_id.size(); i++) temp += "0";
    backtrack(0, banned_id.size(), temp);
    
    return answer.size();
}