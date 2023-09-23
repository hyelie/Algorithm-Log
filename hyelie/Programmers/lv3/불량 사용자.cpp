#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

// banned_id와 user_id가 일치하는지
bool isBanned(string banned_id, string user_id){
    if(banned_id.length() != user_id.length()) return false;
    
    int len = banned_id.length();
    for(int i = 0; i<len; i++){
        if(banned_id[i] == user_id[i] || banned_id[i] == '*') continue;
        // 실수 1. banned_id[i] == '*'로 했어야 했는데 user_id[i] == '*'로 했다.
        else return false;
    }
    return true;
}


/*
모든 banned_id에 대해 가능한 user_id의 후보군들을 나열하고,
permutation/backtrack으로 가능한 모든 조합을 나열하고,
해당 조합에서 겹치는 것을 빼면 되겠네.
 - index를 기준으로 정렬해서 표현하면 될 듯? size가 8이니까 index를 정렬하면 중복 거를 수 있을 듯.
*/

set<string> answer;
unordered_map<string, bool> visited; // visited[i] : user_id[i]를 사용했는지 여부. true then used
vector<vector<int>> candidates; // candidites[i] : banned_id[i]가 적용될 수 있는 user_id index vector
vector<string> user_ids, banned_ids;

void backtrack(int cur_depth, int max_depth, string result){
    if(cur_depth == max_depth){
        sort(result.begin(), result.end());
        answer.insert(result);
        return;
    }
    
    for(int i = 0; i<candidates[cur_depth].size(); i++){
        int user_idx = candidates[cur_depth][i]; // 실수 4. user_idx를 i로 넣었다.
        string s = user_ids[user_idx];
        if(!visited[s]){ // 실수 2. visited 로직을 뺐다.
            visited[s] = true;
            backtrack(cur_depth + 1, max_depth, result + to_string(user_idx)); // 실수 5. user_idx가 아니라 i로 넣었다.
            visited[s] = false;
        }
        
    }
    return;
}

int solution(vector<string> uids, vector<string> bids) {
    // init
    user_ids = uids;
    int user_size = user_ids.size();
    for(string user_id : user_ids){
        visited[user_id] = false;
    }
    
    banned_ids = bids; // 실수 3. uid로 넣었다.
    int banned_size = banned_ids.size();
    candidates.resize(banned_size);
    
    // init candidates
    for(int i = 0; i<banned_size; i++){
        for(int j = 0; j<user_size; j++){
            if(isBanned(banned_ids[i], user_ids[j])){
                candidates[i].push_back(j);
            }
        }
    }
    
    backtrack(0, banned_size, "");
    
    return answer.size();
}