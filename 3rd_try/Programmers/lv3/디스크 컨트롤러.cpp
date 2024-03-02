#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct comp{ // 작업 시간 짧은 거 - 시작 시간 짧은 거
    bool operator() (const vector<int> &a, const vector<int> &b) const{
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
};

bool time_cmp(const vector<int>& a, const vector<int> &b){ // 시작 시간 짧은 거 - 작업 시간 짧은 거
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}


typedef vector<int> vi;
priority_queue<vi, vector<vi>, comp> pq;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), time_cmp);
    
    int wait_sum = 0;
    
    int cur_time = 0;
    
    // simulation
    int i = 0;
    while(1){
        if(pq.empty()){ // pq 비어서 넣는 경우
            if(i < jobs.size()){
                cur_time = jobs[i][0];
                pq.push(jobs[i]);
                i++;    
            }
            else break;
        }
        else{ // pq 비우고, 대기시간 계산
            int running_time = pq.top()[1];
            int request_time = pq.top()[0];
            pq.pop();
            
            cur_time += running_time;
            wait_sum += cur_time - request_time;
            
            while(i < jobs.size() && jobs[i][0] <= cur_time){ // 현재 시간보다 더 빨리 도착한 것들 pq push
                pq.push(jobs[i]);
                i++;
            }
        }
    }
    
    return wait_sum / (int)jobs.size();
}

/*
pq 사용, 평균 제일 줄이는 방식은 작업 길이가 제일 작은 것을 넣는 방식이다.

pq: 대기 중인 것들.
대기 중인 것들 중에서 실행시간이 제일 적은 것을 실행한다.
-> pop뽑았을 때 기준으로 대기시간을 계산해야 함.


*/