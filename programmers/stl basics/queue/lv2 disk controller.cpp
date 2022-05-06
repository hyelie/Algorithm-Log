// 디스크 컨트롤러

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
struct cmp{
    bool operator()(pii& a, pii& b){
        return a.second > b.second;
    };
};


int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    
    int cur_time = 0, wait_time = 0, jobs_idx = 0, jobs_size = jobs.size();
    priority_queue<pii, vector<pii>, cmp> pq;
    while(jobs_idx < jobs_size || !pq.empty()){
        if(!pq.empty()){
            pii cur_job = pq.top();
            wait_time += cur_time - cur_job.first + cur_job.second;
            cur_time += cur_job.second;
            pq.pop();
        }
        while(jobs_idx < jobs_size && jobs[jobs_idx][0] <= cur_time){
            pq.push({jobs[jobs_idx][0], jobs[jobs_idx][1]});
            jobs_idx++;
        }
        if(pq.empty() && jobs_idx < jobs_size){
            pq.push({jobs[jobs_idx][0], jobs[jobs_idx][1]});
            cur_time = jobs[jobs_idx][0];
            jobs_idx++;
        }
    }

    return wait_time / jobs_size;
}