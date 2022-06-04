// 보석 쇼핑

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> um;
    
    set<string> set_gem;
    for(string s : gems) set_gem.insert(s);
    int gem_num = set_gem.size();

    int s = 0, e = 0, s_answer, e_answer, min_len = 100001;

    while(e < gems.size()){
        um[gems[e]]++; e++;
        while(um[gems[s]] > 1 && s < e){
            um[gems[s]]--; s++;    
        }
        if(min_len > e - s && um.size() == gem_num){
            e_answer = e;
            s_answer = s + 1;
            min_len = e - s;
        }
    }
    return {s_answer, e_answer};
}

/*
vector<int> solution(vector<string> gems) {
    unordered_map<string, int> um;
    
    set<string> set_gem;
    for(string s : gems) set_gem.insert(s);
    int gem_num = set_gem.size();

    int s = 0, e = -1, s_answer, e_answer, min_len = 100001;

    while(e < gems.size()-1){
        e++; um[gems[e]]++; 
        while(um[gems[s]] > 1 && s <= e){
            um[gems[s]]--; s++;    
        }
        if(min_len > e - s + 1 && um.size() == gem_num){
            e_answer = e;
            s_answer = s;
            min_len = e - s + 1;
        }
    }
    return {s_answer + 1, e_answer + 1};
}*/