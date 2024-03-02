#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> _set(gems.begin(), gems.end());
    int num_gem_kind = _set.size();
    
    int s = 0, e = 0;
    vector<int> answer = {0, (int)gems.size() + 1};
    
    unordered_map<string, int> um; // gem 개수
    um[gems[0]]++;
    set<string> cur_gems; cur_gems.insert(gems[0]);
    while(1){
        if(cur_gems.size() == num_gem_kind){ // 모두 있는 경우 start++
            if(e - s < answer[1] - answer[0]){ // 답 갱신
                answer[0] = s + 1;
                answer[1] = e + 1;
            }
            
            um[gems[s]]--;
            if(um[gems[s]] == 0) cur_gems.erase(gems[s]);
            s++;
        }
        else{ // 없는 경우 end++
            e++;
            if(e == gems.size()) break;
            um[gems[e]]++;
            cur_gems.insert(gems[e]);
        }
        
        if(s >= gems.size() || e >= gems.size()) break;
        
        if(s > e){
            um[gems[e]] = 0;
            um[gems[s]] = 1;
            cur_gems.erase(gems[e]);
            cur_gems.insert(gems[s]);
            e = s;
        }
    }
    
    return answer;
}