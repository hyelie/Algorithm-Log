#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int answer;
vector<bool> is_used;
string peoples;
vector<string> results;

void permutation(int cur_depth, int max_depth, string &temp){
    if(cur_depth == max_depth){
        results.push_back(temp);
        return;
    }
    
    for(int i = 0; i<peoples.length(); i++){
        if(!is_used[i]){
            is_used[i] = true;
            temp[cur_depth] = peoples[i];
            permutation(cur_depth + 1, max_depth, temp);
            is_used[i] = false;
        }
    }
}

int FindIndex(string line, char target){
    for(int i = 0; i<line.length(); i++){
        if(line[i] == target) return i;
    }
    return -1;
}

bool IsOk(string &line, vector<string> &conditions){
    for(string condition : conditions){
        char first = condition[0];
        char second = condition[2];
        char op = condition[3];
        int length = condition[4] - '0';
        
        int first_index = FindIndex(line, first);
        int second_index = FindIndex(line, second);
        int dist = abs(second_index - first_index) - 1;
        
        if(op == '<' && dist >= length) return false;
        if(op == '=' && dist != length) return false;
        if(op == '>' && dist <= length) return false;
    }
    
    return true;
}

int solution(int n, vector<string> data) {
    answer = 0;
    vector<bool> _is_used(8, false); is_used = _is_used;
    results.resize(0);
    
    
    peoples = "ACFJMNRT";
    
    string temp = "00000000";
    permutation(0, peoples.length(), temp);
    
    int answer = 0;
    for(string result : results){
        if(IsOk(result, data)){
            answer++;   
        }
    }
    
    return answer;
}