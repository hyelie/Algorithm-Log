#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int total_num = order.size();
    
    queue<int> waits; // 대기자 목록. 들어오는 것은 index
    int future_idx = 0; // 제일 근미래에 올 사람의 index
    int time = 0;
    
    int answer = -1;
    
    while(1){
        // 종료조건
        if(time >= total_num * k) break;
        
        // time보다 빨리 와서 그동안 줄을 선 손님들 waitQ에 추가
        while(1){
            if(future_idx < total_num && future_idx * k <= time){
                waits.push(future_idx);
                future_idx++;
            }
            else break;
        }
        
        // 만듬
        if(!waits.empty()){
            time += menu[order[waits.front()]];
        }
        
        // 만들 동안 와서 그동안 줄을 선 손님들 waitQ에 추가
        while(1){
            if(future_idx < total_num && future_idx * k <= time){
                waits.push(future_idx);
                future_idx++;
            }
            else break;
        }
        
        // 대기열 계산. 단, 만들고 나간 시간 == 들어온 시간이면 1을 빼 주어야 함.
        int isDuplicated = (time%k == 0 ? 1 : 0);
        answer = max(answer, (int)waits.size() - isDuplicated);
        
        // 만들었다면, 빼고, 그렇지 않다면 타임트립.
        if(!waits.empty()) waits.pop();
        else{
            time = future_idx * k;
        }
    }
    
    return answer;
}