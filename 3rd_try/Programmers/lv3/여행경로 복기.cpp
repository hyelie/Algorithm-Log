#include <string>
#include <vector>
#include <map>

using namespace std;

int len;
map<string, map<string, int>> edges;

bool backtrack(int cur_depth, int max_depth, string cur_city, vector<string> &result){
    if(cur_depth == max_depth) return true;
    
    for(auto &[next_city, count] : edges[cur_city]){
        if(count == 0) continue;
        
        count--;
        
        result[cur_depth + 1] = next_city;
        bool has_answer = backtrack(cur_depth + 1, max_depth, next_city, result);
        if(has_answer) return true;
        
        count++;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    len = (int) tickets.size();
    for(vector<string> ticket : tickets){
        string from = ticket[0], to = ticket[1];
        edges[from][to]++;
    }
    
    vector<string> result(len+1); result[0] = "ICN";
    backtrack(0, len, "ICN", result);
    return result;
}