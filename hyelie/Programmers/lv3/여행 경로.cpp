#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

int max_depth;
map<string, map<string, int>> edges; // edges[i] : i에 인접한 공항들
vector<string> result;

bool DFS(int cur_depth, string cur_airport){
    if(cur_depth == max_depth){
        return true;
    }
    
    for(auto &[name, count] : edges[cur_airport]){
        if(count == 0) continue;
        edges[cur_airport][name]--;
        result[cur_depth + 1] = name;
        
        bool hasAnswer = DFS(cur_depth+1, name);
        if(hasAnswer) return true;
        
        edges[cur_airport][name]++;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    max_depth = (int) tickets.size();
    for(vector<string> ticket : tickets){
        string src = ticket[0], dest = ticket[1];
        edges[src][dest]++; 
    }
    
    
    
    result.resize(max_depth + 1);
    result[0] = "ICN";
    
    DFS(0, "ICN");
    
    return result;
}