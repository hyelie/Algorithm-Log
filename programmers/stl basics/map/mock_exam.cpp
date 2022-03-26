// 모의고사

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int grading(vector<int>& answers, vector<int>& type){
    int point = 0, type_size = type.size(), type_idx = 0, answers_size = answers.size();
    
    for(int i = 0; i < answers_size;i++){
        if(type_idx == type_size) type_idx = 0;
        
        if(answers[i] == type[type_idx]) point++;
        type_idx++;
    }
    
    return point;
}

vector<int> solution(vector<int> answers) {
    vector<vector<int>> type = {{1,2,3,4,5},
                                 {2,1,2,3,2,4,2,5},
                                 {3,3,1,1,2,2,4,4,5,5}};
    
    map<int, vector<int>> m;
    for(int i = 0; i<3; i++){
        int point = grading(answers, type[i]);
        if(m.find(point) == m.end()){
            m[point] = {i+1};
        }
        else{
            m[point].push_back(i+1);
        }
    }
    
    return max_element(m.begin(), m.end())->second;
}