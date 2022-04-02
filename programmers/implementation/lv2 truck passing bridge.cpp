#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int size = truck_weights.size();
    queue<pii> passing_queue;
    queue<int> waiting_queue;
    int time = 1, cur_weight = truck_weights[0]; // 1초 딱 시작하자마자 들어가는 걸로.
    passing_queue.push({truck_weights[0], time}); time++;
    for(int i = 1; i<size; i++){
        waiting_queue.push(truck_weights[i]);
    } // trucks[i].first : 트럭 weight, .second : truck이 다리에 진입한 시간.
    
    while(!passing_queue.empty()){
        if(passing_queue.front().second + bridge_length <= time){
            cur_weight -= passing_queue.front().first;
            passing_queue.pop();
        } // 나가야 할 때 빼 줌.
        
        if(!waiting_queue.empty() && cur_weight + waiting_queue.front() <= weight){
            passing_queue.push({waiting_queue.front(), time});
            cur_weight += waiting_queue.front();
            waiting_queue.pop();
            time++;
        } // 더 올릴 수 있으면 올리고, time++ 해줌.
        else {
            if(!passing_queue.empty()){
                time = passing_queue.front().second + bridge_length;    
            }
        } // 더 올리지 못하는 경우는 시간을 skip해버림.
        // 이 때 에러가 하나 있었는데. passing_queue가 empty인 상황에서도 front의 값을 읽어오는(메모리 에러) 오류가 있었음.
    }
    
    return time;
}

// 아래 코드보단 조금 효율적으로 바뀜.
// 무조건 시간을 1씩 더해가는 게 아니라 더 이상 올리지 못할때는 시간을 skip해버리기 때문임.

/*

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int clock = 0; // 시간초
    int passing_sum = 0; // 다리를 건너는 트럭의 무게 합
    
    queue<int> q;   // 대기 트럭
    int truck_num = truck_weights.size();
    for(int i = 0; i<truck_num; i++){
        q.push(truck_weights[i]);
    }
    
    queue<pair<int, int>> passing_q;  // first는 진입한 clock(clock+bridge_length가 되면 나가야함), second는 그 차의 무게
    
    while(!q.empty()){
        if(!passing_q.empty() && clock == passing_q.front().first + bridge_length){
            passing_sum -= passing_q.front().second;
            passing_q.pop();
        }
        if(q.front() + passing_sum <= weight){
            passing_sum += q.front();
            passing_q.push({clock, q.front()});
            q.pop();
        }
        clock++;
    }
    clock += bridge_length; // q(대기 queue)가 빈 순간 마지막 차가 다리에 올라왔으므로... clock += bridge_length하는 게 답.
    
    return clock;
}*/

// (다리를 건너는 트럭)에 있는 시간이 length만큼임.
// 1초마다 다 계산가면 100,000,000 - 1억