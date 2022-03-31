// 프린터

#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    for(int priority : priorities){
        pq.push(priority);
    }
    
    int object_value = priorities[location];
    queue<pii> q;
    for(int i = 0; i<priorities.size(); i++){
        if(i == location){
            q.push({priorities[i], 1});
        } else{
            q.push({priorities[i], 0});
        }
    }
    
    int cnt = 0, max_value;
    while(!q.empty()){
        max_value = pq.top(); pq.pop();
        if(max_value > q.front().first){
            while(max_value != q.front().first){
                q.push(q.front());
                q.pop();
            }  
        }
        cnt++;
        if(q.front().second == 1){
            break;
        }
        q.pop();
    }
    
    return cnt;
}









/*int solution(vector<int> priorities, int location) {
    int size = priorities.size();
    int answer = 0;
    
    queue<pair<int, int>> q;
    // 내가뽑고 싶은 거 : second에 1
    for(int i = 0; i<size; i++){
        if(i == location) q.push({priorities[i], 1});
        else q.push({priorities[i], 0});
    }
    
    int num = 1;
    while(!q.empty()){
        int front_priority = q.front().first; // J에 대한 정보
        int ismy = q.front().second;
        q.pop();
        
        bool isOK = true;   // J를 출력해도 되는지
        int qsize = q.size();
        while(qsize--){
            if(q.front().first > front_priority) isOK = false;
            q.push({q.front().first, q.front().second});
            q.pop();
        }
        if(!isOK){
            q.push({front_priority, ismy});
        }
        else{
            if(ismy){
                answer = num;
                break;
            }
            num++;
        }
        
    }
    
    
    return answer;
}*/

// circular queue