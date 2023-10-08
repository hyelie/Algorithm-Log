#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef long long ll;

struct info{
    int point;
    int income_time;
    int running_time;
};

// 정렬 기준 : 1. 빨리 오는 것 2. 우선순위 높은 것
struct futurecmp{
    bool operator()(info &a, info &b){
        if(a.income_time == b.income_time) return a.point > b.point; // 우선순위 숫자 작은 게 top에
        return a.income_time > b.income_time; // income time 빠른 게 top에
    }
};

// 정렬 기준 : 1. 우선순위 높은 것 2. 빨리 오는 것 
struct waitcmp{
    bool operator()(info &a, info &b){
        if(a.point == b.point) return a.income_time > b.income_time; // income time 빠른 게 top에
        return a.point > b.point; // 우선순위 숫자 작은 게 top에
    }
};

// 초기화 : 시작 시간이 t보다 작은 것들을 waits에 넣음
void pushIntoWaitsLessThanT(int t, priority_queue<info, vector<info>, waitcmp> &waits, priority_queue<info, vector<info>, futurecmp> &future){
    while(1){
        if(future.empty()) break;
        if(future.top().income_time > t) break;
        if(future.top().income_time <= t){
            waits.push(future.top());
            future.pop();
        }
    }
}

vector<long long> solution(vector<vector<int>> program) {
    priority_queue<info, vector<info>, waitcmp> waits; // 실행 대기 중인 thread queue
    priority_queue<info, vector<info>, futurecmp> future; // 미래에 thread queue
    for(vector<int> p : program){
        info i;
        i.point = p[0];
        i.income_time = p[1]; 
        i.running_time = p[2];
        future.push(i);
    }
    
    // 초기화
    int time = 0;
    pushIntoWaitsLessThanT(time, waits, future);
    cout<<endl;
    
    // answer[0] : 모든 프로그램 종료 시간, answer[i] : 점수가 i인 프로그램 대기시간 합
    vector<long long> answer(11, 0);
    while(1){
        if(waits.empty()){
            // 종료조건
            if(future.empty()) break;
            
            // future가 남아있으면 그것 넣음
            waits.push(future.top()); 
            time = future.top().income_time;
            future.pop();
        }
        
        // waits 중 제일 높은 것 실행 중으로 변경
        info cur = waits.top(); 
        waits.pop();
        // cout<<"현재 시간 : "<<time<<endl;
        // cout<<"현재 실행 중 : "<<cur.point<<", "<<cur.income_time<<", "<<cur.running_time<<endl;
        
        // 해당 thread의 대기시간 추가
        int wait_time = time - cur.income_time;
        answer[cur.point] += wait_time;
        // cout<<"대기시간 : "<<wait_time<<endl;
        
        time += cur.running_time;
        // cout<<"끝난 시간 : "<<time<<endl;
        pushIntoWaitsLessThanT(time, waits, future);
        
        
        // cout<<endl;
    }
    answer[0] = time;
    
    return answer;
}