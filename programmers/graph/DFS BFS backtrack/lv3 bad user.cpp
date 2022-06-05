// 불량 사용자

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int answer = 0;
set<string> vs;

void permutation(int cur_r, int max_r, vector<string>& user_id, vector<bool>& isUsed, vector<string>& banned_id, vector<vector<bool>>& similar, vector<int>& result){
    if(cur_r == max_r){
        bool flag = true;
        for(int i = 0; i<result.size(); i++){
            if(similar[result[i]][i] == false) flag = false;
        }
        if(flag){
            string duplicateCheckString = "";
            for(int i : result){
                duplicateCheckString += to_string(i);
            }
            sort(duplicateCheckString.begin(), duplicateCheckString.end());
            vs.insert(duplicateCheckString);
        }
        return;
    }
    
    for(int i = 0; i<user_id.size(); i++){
        if(!isUsed[i]){
            isUsed[i] = true;
            result[cur_r] = i;
            permutation(cur_r + 1, max_r, user_id, isUsed, banned_id, similar, result);
            isUsed[i] = false;
        }
    }
}

bool isSimilar(string user_id, string banned_id){
    if(user_id.length() != banned_id.length()) return false;
    for(int i = 0; i<user_id.length(); i++){
        if(banned_id[i] == '*') continue;
        if(user_id[i] != banned_id[i]) return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<bool>> similar(user_id.size(), vector<bool>(banned_id.size()));
    for(int i = 0; i<user_id.size(); i++)
        for(int j = 0; j<banned_id.size(); j++)
            similar[i][j] = isSimilar(user_id[i], banned_id[j]);
    
    vector<bool> isUsed(user_id.size(), false);
    vector<int> result(banned_id.size());
    
    permutation(0, banned_id.size(), user_id, isUsed, banned_id, similar, result);
    
    return vs.size();
}