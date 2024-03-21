#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

typedef pair<string, int> psi;

bool cmp (const psi &a, const psi &b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
}

map<int, map<string, int>> m; // [course 길이, [course 이름, 회수]]

void backtrack(int cur_depth, int max_depth, int prev_idx, string &origin, string result){
    if(cur_depth == max_depth){
        sort(result.begin(), result.end(), less<char>());
        m[max_depth][result]++;
        return;
    }
    
    for(int i = prev_idx + 1; i<origin.length(); i++){
        result.push_back(origin[i]);
        backtrack(cur_depth + 1, max_depth, i, origin, result);
        result.pop_back();
    }
}

void cal_combination(string &order, vector<int>& course){
    for(int c : course) backtrack(0, c, -1, order, "");
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(string order : orders) cal_combination(order, course);
    
    vector<string> answer;
    for(auto &[course_len, course_map] : m){
        // len짜리 모두 v에 넣고 정렬
        vector<psi> v;
        for(auto &[course_item, num] : course_map){
            v.push_back({course_item, num});
        }
        sort(v.begin(), v.end(), cmp);
        
        
        // v에서 제일 큰것만 뽑음
        int max_num = v[0].second;
        for(int i = 0; i<v.size(); i++){
            if(v[i].second == max_num && v[i].second > 1) answer.push_back(v[i].first);
        }
    }
    
    sort(answer.begin(), answer.end(), less<string>());
    
    return answer;
}