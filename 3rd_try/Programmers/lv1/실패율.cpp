#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, double> pid;

int lb(vector<int> &stages, int target){
    int start = 0, end = stages.size(), mid;
    while(start < end){
        mid = (start + end) / 2;
        if(target <= stages[mid]) end = mid; // *** 실수: stages를 안 걺
        else start = mid + 1;
    }
    return end;
}

int ub(vector<int> &stages, int target){
    int start = 0, end = stages.size(), mid;
    while(start < end){
        mid = (start + end) / 2;
        if(target < stages[mid]) end = mid;
        else start = mid + 1;
    }
    return end;
}

bool cmp(pid &a, pid &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end(), less<int>());
    
    int len = stages.size();
    vector<pid> arr; // [stage, 실패율]
    for(int i = 1; i<=N; i++){
        // int ub_index = upper_bound(stages.begin(), stages.end(), i) - stages.begin();
        // int lb_index = lower_bound(stages.begin(), stages.end(), i) - stages.begin();
        int ub_index = ub(stages, i), lb_index = lb(stages, i);
        if(len == lb_index){ // *** 실수: 잘못 풂
            arr.push_back({i, 0});
        }
        else{
            arr.push_back({i, ((double)(ub_index - lb_index)/(len - lb_index))});    
        }
        
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    vector<int> answer;
    for(pid elem : arr){
        answer.push_back(elem.first);
    }
    return answer;
}

/*
해당 stage 끝 index - 해당 stage 시작 index + 1
/
len - 해당 stage 시작 index



ub index - lb index
/
len - lb index


풀이 30분, 디버깅 6분
*/