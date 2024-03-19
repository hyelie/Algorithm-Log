#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int num_column;
vector<string> candidates; // 후보키 후보
vector<bool> used(8, false);

void backtrack(int cur_depth, int max_depth, int prev_idx, string result){
    if(cur_depth == max_depth){
        candidates.push_back(result);
        return;
    }
    
    for(int i = prev_idx + 1; i<num_column; i++){
        if(!used[i]){
            used[i] = true;
            backtrack(cur_depth + 1, max_depth, i, result + to_string(i));
            used[i] = false;
        }
    }
}

vector<vector<string>> relation;
bool is_candidate_key(string candidate){
    map<string, int> m;
    for(vector<string> row : relation){
        string key = "";
        for(char c : candidate){
            int idx = c - '0';
            key += row[idx] + "_";
        }
        if(m[key] != 0) return false;
        m[key]++;
    }
    return true;
}

bool is_already_exists(set<string>& candidate_keys, string candidate){
    for(string key : candidate_keys){
        if(candidate.find(key) != string::npos) return true;
    }
    return false;
}

int solution(vector<vector<string>> _relation) {
    // init
    relation = _relation;
    num_column = relation[0].size();
    
    // 가능한 모든 후보키 집합 구함: size 작은 것 부터 나옴
    for(int i = 1; i<=num_column; i++){
        backtrack(0, i, -1, "");
    }
    
    // minimality 검사
    map<string, bool> is_unique;
    vector<string> uniques;
    for(string candidate: candidates){
        bool is_candidate_unique = is_candidate_key(candidate);
        is_unique[candidate] = is_candidate_unique;
        if(is_candidate_unique) uniques.push_back(candidate);
    }
    
    set<string> candidate_keys;
    for(string candidate: uniques){
        bool is_minimal = true;
        for(int i = 0; i<candidate.length(); i++){
            // ith index 빼고 나머지 구성
            string temp_key = candidate.substr(0, i) + candidate.substr(i+1);
            if(is_unique[temp_key]){
                is_minimal = false;
                break;
            }
        }
        if(is_minimal) candidate_keys.insert(candidate);
    }

    return candidate_keys.size();
}

/*
1. 모든 column에 대해 모든 후보키 후보를 구함
2. 후보키가 진짜 후보키인지 검증
3. 후보키가 최소성을 만족하는지 검증

풀이 15분
디버깅 10분(오류 잡기) + 13분(틀린 것 해결)
*/