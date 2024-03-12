#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int string_to_min(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return 60*h + m;
}

bool cmp(vector<string> &a, vector<string> &b){ // 시작 시간 빠른 것 - 이름 빠른 것
    int a_start = string_to_min(a[1]);
    int b_start = string_to_min(b[1]);
    if(a_start == b_start){
        return a[0] < b[0];
    }
    return a_start < b_start;
}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), cmp);
    
    vector<string> answer;
    stack<vector<string>> stk; // stk.top(): 현재 진행중인 과제
    
    // init
    int cur_time = string_to_min(plans[0][1]), i = 1;
    stk.push(plans[0]);
    while(1){
        // 종료조건
        if(i >= plans.size()) break;
        
        // 만약 진행중인 과제가 없다면 제일 빨리 있는 과제로 시간을 옮기고, 해당 과제 시작.
        if(stk.empty()){
            cur_time = string_to_min(plans[i][1]);
            stk.push(plans[i]);
            i++;
            continue;
        }
        // 현재 진행중인 과제를 끝낼 수 있는 경우
        if(cur_time + stoi(stk.top()[2]) <= string_to_min(plans[i][1])){
            answer.push_back(stk.top()[0]);
            cur_time += stoi(stk.top()[2]);
            stk.pop();
            continue;
        }
        // 끝낼 수는 없지만 조금이나마 진행하는 경우
        else{
            int top_remain_time = stoi(stk.top()[2]);
            top_remain_time -= (string_to_min(plans[i][1]) - cur_time); // 항상 0보다 큼. 진행도를 줄이고
            stk.top()[2] = to_string(top_remain_time);
            
            cur_time = string_to_min(plans[i][1]);
            stk.push(plans[i]); i++; // 다음 과제를 시작함.
        }
    }
    
    // 다 끝나면 남은 것 처리
    while(!stk.empty()){
        string name = stk.top()[0]; stk.pop();
        answer.push_back(name);
    }
    return answer;
}

/*
simulation 문제.
*/