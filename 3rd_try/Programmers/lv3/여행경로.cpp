#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int len;
vector<bool> used;
vector<vector<string>> tickets;

bool Backtrack(int cur_depth, int max_depth, string cur_city, vector<string> &result){
    if(cur_depth == max_depth){
        return true;
    }
    
    for(int i = 0; i<len; i++){
        if(!used[i] && tickets[i][0] == cur_city){
            used[i] = true;
            result[cur_depth+1] = tickets[i][1];
            bool backtrack_result = Backtrack(cur_depth + 1, max_depth, tickets[i][1], result);
            if(backtrack_result) return true;
            used[i] = false;
        }
    }
    
    return false;
}

bool cmp(vector<string>& a, vector<string>& b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

vector<string> solution(vector<vector<string>> _tickets) {
    // init
    len = _tickets.size();    
    vector<bool> _used(len, false);
    used = _used;
    tickets = _tickets;
    
    sort(tickets.begin(), tickets.end(), cmp);
    
    // backtrack
    vector<string> result(len+1, "");
    result[0] = "ICN";
    Backtrack(0, len, "ICN", result);
    
    return result;
}